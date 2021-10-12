#! /usr/bin/env python3
from antlr_funcs import *
import argparse
import sys
import itertools
import subprocess
import re

def main():
    #read in the function and file we weant to look at
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", "--file_name", help="Input file to look at",
            type=str, required=True)
    parser.add_argument("-f", "--out_file", help="Output file name",
            type=str, required=False, default="new_code_expand.c")
    parser.add_argument("-p", "--pre_process", help="File with list of files for pre-processing.\
            File names must be absolute. Only one file name per line.",
            type=str, required=False, default="")

    args = parser.parse_args()
    prog_name = args.file_name
    out_name = args.out_file
    pre_process = args.pre_process

    #this global things feels really wrong, but it keeps me from breaking the
    #way things are called in the loop at the bottom of the function
    global funcs_and_args
    #functions and their return types
    global funcs_and_rts
    global macros
    dont_eval=[]
    okay_to_eval=[]
    if pre_process != "":
        #This means we have a file to parse
        #File should have a new line for each file to parse
        #Files named should be .c files
        print("Starting pre-processing")
        funcs_and_args,funcs_and_rts,macros,dont_eval,okay_to_eval = get_json_data(pre_process,infile=prog_name)
        print("Pre-processing done")
    else:
        funcs_and_rts = {}
        funcs_and_args = {}
        macros = None

    _pp_prog_name=f"{prog_name}.pp"
    macros=preprocess(macros,prog_name,_pp_prog_name)

    #if not(macros == False):
    #    _pp_prog_name=f"{prog_name}.pp"
    #    macros=preprocess(macros,prog_name,_pp_prog_name)
    #else:
    #    macros=preprocess(None,prog_name,f"{prog_name}.pp")
    #    _pp_prog_name=f"{prog_name}"


    from os import path as path
    fix_ingred_id=path.splitext(path.basename(f"{prog_name}"))[0]
    bl_filename=f"fn_blacklist.{fix_ingred_id}.txt"

    #original program
    cur_pro = ""
    with open(_pp_prog_name, 'r') as infile:
        cur_pro = infile.read()

    #get the dictionary that maps line numbers with the re-write
    p,t = get_tree_from_file(_pp_prog_name)
    print_ctx_bfs(t,"original_tree")
    d1 = get_all_decs(t)
    #loop to run all code transformations
    #order matters, don't re-arrange
    change_funcs = [expand_case, expand_conditionals, if_else_break, insert_loop_braces, expand_if_else, expand_sizeof, single_declarations, expand_decs,expand_func_args]
    apply_changes = [gen_case, gen_conditionals, gen_if_else_break, gen_loop_braces, gen_if_changes, gen_expand_changes, gen_dec_changes, gen_dec_changes,gen_func_changes]
    j = 0
    i = 0
    f_n = 0
    print("Starting Transformations")
    while i < len(change_funcs):
        """
        if i != 0:
            p,t = get_tree_from_string(cur_pro)
        rewrite = change_funcs[i](t)
        cur_pro = apply_changes[i](cur_pro, rewrite)
        """
        again = True
        if i == len(change_funcs)-1:
            break
        while again:
            print(f"Start {change_funcs[i].__name__} pass")
            old_pro = cur_pro
            if j != 0:
                p,t = get_tree_from_string(cur_pro)
            rewrite = change_funcs[i](t)
            cur_pro = apply_changes[i](cur_pro, rewrite)
            print("End pass")
            #print_inter_file(f_n, cur_pro)
            #print_ctx_bfs(t,f"help_pre_{f_n}")
            f_n += 1
            if i == len(change_funcs)-2:
                print(f"Start {change_funcs[i+1].__name__} pass")
                p,t = get_tree_from_string(cur_pro)
                rewrite = change_funcs[i+1](t)
                cur_pro = apply_changes[i+1](cur_pro, rewrite)
                print("End pass")
                #print_inter_file(f_n, cur_pro)
                f_n += 1

            j += 1
            again = not(old_pro == cur_pro) and i == len(change_funcs)-2
            #print(again)
        i += 1
    print("all done with passes")
    #FIX-INGREDIENTS
    write_new_program(cur_pro, f"{out_name}.prev")
    p,t = get_tree_from_string(cur_pro)
    d2 = get_all_decs(t)
    #dictionary where:
    # key = function_name //use get_func_name() on a function definition context
    # value = [new_declaration_nodes] // only declarations introducted by the code in this program
    new_decs = get_dec_diffs(d1,d2)
    for i,k in enumerate(new_decs.keys()):
        nd="\n - "+"\n - ".join([get_string2(n) for n in new_decs[k]])
        print(f"{i} :  [{k}] {type(new_decs[k])}  [new function decls] {nd}")

    print_ctx_bfs(t,"help")
    printer=ScopeListener()
    printer.set_functions(dont_eval+okay_to_eval)
    walker = ParseTreeWalker()
    walker.walk(printer,t)
    scope_vars = get_function_info(functions=get_functions(t),fscope=printer.scopes,dont_eval=dont_eval)
    #fix_loc_rewrites = get_fix_loc_rewrites(scope_vars)
    fix_loc_rewrites,new_funcs = get_fix_loc_subfns(scope_vars,new_decs,okay_to_eval,id_=fix_ingred_id,root=t)
    cur_pro = gen_fix_loc_changes(cur_pro, fix_loc_rewrites)

    #write out the new program
    write_new_program(cur_pro, out_name)
    with open(bl_filename,"w") as o:
        for i in new_funcs:
            o.write(f"{i}\n")
        o.close()

def print_inter_file(i, cur_pro):
    with open(f"tmp{i}.c", 'w') as out_f:
        print(f"Writing file {i}")
        out_f.write(cur_pro)


def expand_case(ctx):
    #insert '{' after each "case():"
    #insert '}' at end of switch
    sw = "<class 'CParser.CParser.SelectionStatementContext'>"
    lsc = "<class 'CParser.CParser.LabeledStatementContext'>"
    fns = get_functions(ctx)
    rewrites = []
    for f in fns:
        switches = find_ctx(f, sw)
        #get rid of the if statements
        s = [x for x in switches if x.getChild(0).getText() == 'switch']
        for w in s:
            #get all the Labled StatementContexts
            cs = find_ctx(w, lsc)
            for c in cs:
                #append the start and end location of the
                #case so we can and curles at the re-write
                #the place right after the colon
                if c.getChild(0).getText() == 'case':
                    sl = get_start_loc(c.getChild(3))
                    #the place at the end
                    el = get_end_loc(c.getChild(3))
                if c.getChild(0).getText() == 'default':
                    sl = get_start_loc(c.getChild(2))
                    #the place at the end
                    el = get_end_loc(c.getChild(2))
                rewrites.append((sl,el))
    return rewrites

def gen_case(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    bc = '{'
    ec = '}'
    deltas = {}
    for r in rewrite:
        (sr,sc),(er,ec) = r
        #add open curly to case
        if sr-1 not in deltas:
            deltas[sr-1] = 1
            d = 0
        else:
            deltas[sr-1] += 1
            d = deltas[sr-1] - 1
        ln = lns[sr-1]
        lns[sr-1] = f"{ln[:sc-1+d]}{{{ln[sc-1+d:]}"

        #add end curly to end
        #first see if we have anything changed by the addition of
        #the curly brace from above
        if er-1 in deltas:
            d = deltas[er-1]
        else:
            d = 0
        ln = lns[er-1]
        lns[er-1] = f"{ln[:ec+1+d]}}}{ln[ec+1+d:]}"

    return "\n".join(lns)

def insert_loop_braces(ctx):
    #get all functions
    loop_stmt = "<class 'CParser.CParser.IterationStatementContext'>"
    if_stmt = "<class 'CParser.CParser.SelectionStatementContext'>"
    fns = get_functions(ctx)
    rewrites = []
    #for else conditions we will want to check the 5th child of SelectionStatementContext
    #and do the same thing
    for f in fns:
        loops = find_ctx(f, loop_stmt)
        ifs = find_ctx(f, if_stmt)
        loops.extend(ifs)
        #get all loops in functions
        for l in loops:
            if l.getText().startswith("do"):
                continue
            #check to see if there are curly braces
            l_body = l.getChild(4)
            if l_body.getText().startswith("{"):
                pass
            else:
                #add if necessary
                rewrites.append((get_start_loc(l_body),get_end_loc(l_body)))
            if l.getChildCount() == 7:
                #we have if...else
                l_body = l.getChild(6)
                if l_body.getText().startswith("{"):
                    continue
                else:
                    rewrites.append((get_start_loc(l_body),get_end_loc(l_body)))
    return rewrites

def expand_conditionals(ctx):
    #get the conditional statement
    if_stmt = "<class 'CParser.CParser.SelectionStatementContext'>"
    fns = get_functions(ctx)
    rewrites = []
    for f in fns:
        ifs = find_ctx(f, if_stmt)
        for l in ifs:
            if not l.getChild(4).getText().startswith('{'):
                #add in the curly brace to start and end of IF
                rewrites.append((get_start_loc(l.getChild(4)),get_end_loc(l.getChild(4))))
            if l.getChildCount() != 7:
                continue
            if not l.getChild(6).getText().startswith('{'):
                rewrites.append((get_start_loc(l.getChild(6)),get_end_loc(l.getChild(6))))
                #add in the curly brace to start and end of ELSE
        #find the body
        #wewrite it the whole thing to not suck
        #profit
    return rewrites

def gen_conditionals(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    deltas = {}
    for r in rewrite:
        s,e = r
        #may want to do this with a line delta but I'll test this first
        if s[0] == e[0]:
            #start and end are on the same line and need to add 1 to the index for the end

            #start curly
            if s[0]-1 in deltas:
                d = deltas[s[0]-1]
                deltas[s[0]-1] += 1
            else:
                deltas[s[0]-1] = 1
                d = 0

            ln = lns[s[0]-1]
            lns[s[0]-1] = f"{ln[:s[1]-1+d]}{{{ln[s[1]-1+d:]}"

            #end curly
            if e[0]-1 in deltas:
                d = deltas[e[0]-1]
                deltas[e[0]-1] += 1

            ln = lns[e[0]-1]
            lns[s[0]-1] = f"{ln[:e[1]+1+d]}}}{ln[e[1]+1+d:]}"
        else:
            ln = lns[s[0]-1]
            lns[s[0]-1] = f"{ln[:s[1]-1]}{{{ln[s[1]-1:]}"
            if s[0]-1 in deltas:
                deltas[s[0]-1] += 1
            else:
                deltas[s[0]-1] = 1
            ln = lns[e[0]-1]
            lns[e[0]-1] = f"{ln[:e[1]+1]}}}{ln[e[1]+1:]}"
            #start and end are on different lines and don't need to add 1 to the index
    ret = "\n".join(lns)
    of = open('tmp_fmt', 'w')
    of.write(ret)
    of.close()
    s,o = subprocess.getstatusoutput(f"indent -kr -st -l300 tmp_fmt")
    return o
    #return ret

def if_else_break(ctx):
    if_stmt = "<class 'CParser.CParser.SelectionStatementContext'>"
    fns = get_functions(ctx)
    rewrites = []
    for f in fns:
        ifs = find_ctx(f, if_stmt)
        for l in ifs:
            if l.getChildCount() == 7:
                #we have if...else
                l_body = l.getChild(6)
                if l_body.getText().startswith("{"):
                    continue
                else:
                    #check to see if the if and the else are on the same line
                    if_start = get_start_loc(l.getChild(0))
                    else_start = get_start_loc(l.getChild(5))
                    else_stmt_start = get_start_loc(l_body)
                    else_stmt_end = get_end_loc(l_body)
                    if if_start[0] != else_start[0]:
                        continue
                    if else_stmt_start[0] == else_start[0]:
                        #both are on the same line and we need a newline between them
                        rewrites.append((else_stmt_start,else_stmt_end))
    return rewrites

def gen_if_else_break(cur_prog, rewrites):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    for b,e in rewrites:
        l = lns[b[0]-1]
        es = b[1]
        lns[b[0]-1] = f"{l[:es-1]}\n{{\n{l[es-1:]}"
        l = lns[e[0]-1]
        ee = e[1]
        lns[e[0]-1] = f"{l[:ee+1]}\n}}{l[ee+1:]}"
    return "".join(lns)

def gen_loop_braces(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    for b,e in rewrite:
        #print("1" + lns[b[0]-1])
        spaces = get_line_spaces(lns[b[0]-2])
        lns[b[0]-1] = f"{spaces}{{\n{lns[b[0]-1]}"
        #print("2" + lns[e[0]-1])
        lns[e[0]-1] = f"{lns[e[0]-1]}{spaces}}}\n"
    return "".join(lns)

def gen_fix_loc_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    for r in rewrite:
        code, loc = r
        spaces = get_line_spaces(lns[loc[0]-2])
        lns[loc[0]-2] += f"{spaces}{code.strip()}\n"
    return "".join(lns)

def expand_if_else(ctx):
    sel_stmt = "<class 'CParser.CParser.SelectionStatementContext'>"
    fns = get_functions(ctx)
    rewrites = {}
    #This gives us all functions in the file and it's args
    for f in fns:
        funcs_and_rts[get_func_name(f)] = f.getChild(0).getText()
    #for all functions
    for f in fns:
        ifs = find_ctx(f, sel_stmt)
        all_types, all_vars = get_all_vars(f,True)
        #for all if statements
        for i in ifs:
            fcs = get_function_calls(i.getChild(2))
            #print([f.getText() for f in fcs])
            z = itertools.permutations(fcs,2)
            for zz in z:
                if is_descendant(zz[0],zz[1]):
                    if zz[0] in fcs:
                        fcs.remove(zz[0])
            #print([f.getText() for f in fcs])
            #print("get_functions")
            #print([f for f in funcs_and_rts.keys()])
            #all function calls inside the if
            for c in fcs:
                f_name = c.getChild(0).getText()
                if f_name in funcs_and_rts:
                    func_args = c.getChild(2).getText()
                    r_vars = gen_new_vars(all_vars, 1)
                    all_vars.extend(r_vars)
                    start_loc = get_start_loc(c)
                    end_loc = get_end_loc(c)
                    dec = r_vars[0]
                    pctx = get_top_dec_parent(i)
                    func_loc = get_start_loc(pctx)
                    rewrites[start_loc, end_loc] = (f"{funcs_and_rts[f_name]} {dec} = {c.getText()};", dec, func_loc)
                    #rewrites[start_loc, end_loc] = (f"{funcs_and_rts[f_name]} {dec} = {c.getText()};", dec)
    return rewrites

def expand_sizeof(ctx):
    sel_stmt = []
    sel_stmt.append("<class 'CParser.CParser.SelectionStatementContext'>")
    sel_stmt.append("<class 'CParser.CParser.IterationStatementContext'>")
    sel_stmt2 = "<class 'CParser.CParser.ShiftExpressionContext'>"
    fns = get_functions(ctx)
    rewrites = {}
    dec = "unsigned long "
    #go through all the functions
    for f in fns:
        c_vars = set()
        loops_selections = find_ctx_list(f, sel_stmt)
        # for all loops and conditionals
        for l in loops_selections:
            if l.getText().startswith("do"):
                continue
            #this is just the stuff between parens in the statement l.getChild(2)
            sizes = find_ctx(l.getChild(2), sel_stmt2)
            #for all the sizeof() statements get the re-write information
            size = [x for x in sizes if x.getText().startswith('sizeof(')]
            #get a new variable for every sizeof in the statement
            vs = [f"tlv_size_{x}" for x in range(len(size))]
            i = 0
            for s in size:
                start_loc = get_start_loc(s)
                end_loc = get_end_loc(s)
                if vs[i] in c_vars:
                    rewrites[start_loc, end_loc] = (f"{vs[i]}= {s.getText()};", f"{vs[i]}")

                else:
                    rewrites[start_loc, end_loc] = (f"{dec}{vs[i]}= {s.getText()};", f"{vs[i]}")
                    c_vars.add(vs[i])
                    i += 1

    return rewrites

def gen_if_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    diff = 0
    prev_line = 0
    for key,val in rewrite.items():
        start_loc, end_loc = key
        func_call,var_use,p_loc = val
        #if the start and end loc lines are the same
        if key[0][0] == key[1][0]:
            if prev_line != start_loc[0]:
                diff = 0
            ln = lns[start_loc[0]-1]
            start = ln[:start_loc[1]-1-diff]
            end = ln[end_loc[1]+1-diff:]
            middle = var_use

            pre_len = len(ln)
            spaces = get_line_spaces(ln)
            line_change = f"{start}{middle}{end}"

            diff = pre_len - len(line_change)

            lns[start_loc[0]-1] = f"{line_change}"
            lns[p_loc[0]-2] += f"{spaces}{func_call}\n"

            prev_line = start_loc[0]
        #if multi-line we need to compress the functioncall line to 1
        else:
            print("You should really have done this")
    return "".join(lns)

def gen_expand_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    diff = 0
    prev_line = 0
    for key,val in rewrite.items():
        start_loc, end_loc = key
        func_call,var_use = val
        #if the start and end loc lines are the same
        if key[0][0] == key[1][0]:
            if prev_line != start_loc[0]:
                diff = 0
            ln = lns[start_loc[0]-1]
            start = ln[:start_loc[1]-1-diff]
            end = ln[end_loc[1]+1-diff:]
            middle = var_use

            pre_len = len(ln)
            spaces = get_line_spaces(ln)
            line_change = f"{start}{middle}{end}"

            diff = pre_len - len(line_change)

            lns[start_loc[0]-1] = f"{line_change}"
            lns[start_loc[0]-2] += f"{spaces}{func_call}\n"

            prev_line = start_loc[0]
        #if multi-line we need to compress the functioncall line to 1
        else:
            print("You should really have done this")
    return "".join(lns)

def expand_func_args(ctx):
    loop_stmt = "<class 'CParser.CParser.IterationStatementContext'>"
    loops = find_ctx(ctx, loop_stmt)
    whiles = [x for x in loops if ('for' in x.getChild(0).getText() or 'while' in x.getChild(0).getText())]
    lps = [x.getChild(2) for x in whiles]
    #find all functions, record their names and paramaters
    fns = get_functions(ctx)
    rewrites = {}
    start_locs = {}
    #This gives us all functions in the file and it's args
    for f in fns:
        funcs_and_args[get_func_name(f)] = get_func_args(f)
    #print(funcs_and_args)
    #for each function find all <class 'CParser.CParser.PostfixExpressionContext'>
    for f in fns:
        skip = False
        new_vars = []
        all_types, all_vars = get_all_vars(f,True)
        pecs = find_ctx(f, "<class 'CParser.CParser.PostfixExpressionContext'>")
        pecs = [p for p in pecs if p.getChildCount() > 1 and p.getChild(0).getText() in funcs_and_args]
        pecs = remove_inner_funcs(pecs)
        #print([p.getChild(0).getText() for p in pecs])
        try:
            for p in pecs:
                #make sure we don't do anything with things inside the conditional check
                #of the while or for loop
                for l in lps:
                    if is_descendant(p, l):
                        skip = True
                if skip:
                    skip = False
                    continue
                f_name = p.getChild(0).getText()
                #print(f"function {f_name} is present with args {p.getChild(2).getText()}")
                #print(f"child count {p.getChildCount()}")
                func_args = parse_func_call_args(p)
                func_arg_names = [get_string2(x) for x in func_args]
                if func_arg_names == [')']:
                    continue
                #replace index in function arguments
                rep = []
                j = 0
                #Find indexes to replace.
                #I do this in two passes so I can create
                #all the new variables in one shot
                #print(all_vars)
                #should do this better but without going global this works
                all_vars = [a for a in all_vars if a.startswith("tlv")]
                for i in func_arg_names:
                    #if i not in all_vars and has_func(func_args[j]):
                    if i not in all_vars:
                        rep.append(j)
                    j += 1
                # only here if we have 1 or more arguments to pull out
                if len(rep) > 0:
                    #get new variables to use
                    start_loc = get_start_loc(p)
                    #sometimes we are in a situation like func(a) + func(b)
                    #and a needs to be tlv1 and b tlv2
                    if start_loc[0] in start_locs:
                        start_locs[start_loc[0]] = start_locs[start_loc[0]] + 1
                    else:
                        start_locs[start_loc[0]] = 0
                    r_vars = gen_new_vars(new_vars + all_vars, len(rep)+start_locs[start_loc[0]])
                    r_vars.reverse()
                    end_loc = get_end_loc(p)
                    #print(f"start location {start_loc} end location = {end_loc}")
                    #add to the list of all variables so they are not used
                    #again in the same function on another call
                    #all_vars.extend(r_vars)
                    fun_arg_types = funcs_and_args[f_name]
                    #print(f"{f_name} has types {fun_arg_types}")
                    #added this cause we don't need functions that take
                    #const args to make the varialbes we send them const
                    de_const(fun_arg_types)

                    #This happens in nested situations and for now
                    #I ignore it silently
                    if len(func_args) > len(fun_arg_types):
                        #print(f"messed up here with {p.getText()}")
                        continue

                    new_arg_string = f"{f_name}("
                    new_var_dec = ""
                    for i in range(len(func_args)):
                        if i in rep:
                            #replace that variable
                            v = r_vars.pop()
                            new_var_dec += f"{fun_arg_types[i][0]} {v} = {func_arg_names[i]};\n"
                            new_arg_string += f"{v},"
                            #print(f"{fun_arg_types[i][0]} {v} = {func_arg_names[i]};\n")
                        else:
                            #use what was already there
                            new_arg_string += f"{func_arg_names[i]},"
                    rewrites[start_loc,end_loc] = (new_var_dec,new_arg_string[:-1]+')')
        except Exception as e:
            print(f"messed up here with {p.getText()}")
            print(e)
            continue

    #record the changes needed to re-write the code
    return rewrites

def has_func(ctx):
    nums = find_ctx(ctx,"<class 'CParser.CParser.PostfixExpressionContext'>")
    if len(nums) == 1:
        return True
    return False

def remove_inner_funcs(ctx_list):
    ret_list = ctx_list
    for c in ctx_list:
        inner = find_ctx(c, "<class 'CParser.CParser.PostfixExpressionContext'>")
        for i in inner:
            if i in ctx_list:
                ret_list.remove(i)
    return ret_list

def gen_func_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    tab = chr(32) * 4
    line_deltas = {}
    for key,val in rewrite.items():
        start_loc, end_loc = key
        var_decs,func_call = val
        #if the start and end loc lines are the same
        if key[0][0] == key[1][0]:
            if key[0][0] not in line_deltas:
                ln = lns[start_loc[0]-1]
                start = ln[:start_loc[1]-1]
                end = ln[end_loc[1]+1:]
                middle = val[1]
                spaces = get_line_spaces(ln)
                var_decs = indent_by_newline(var_decs, spaces, tab)
                line_change = f"{tab}{start}{middle}{end}"
                line_deltas[key[0][0]] = len(line_change) - len(lns[start_loc[0]-1])
                lns[start_loc[0]-1] = f"{spaces}{{\n{var_decs}{line_change}{spaces}}}\n"
            else:
                orig_len = len(lns[start_loc[0]-1]) + line_deltas[key[0][0]]
                s_lns = lns[start_loc[0]-1].split('\n')
                ln = s_lns[2]
                spaces = get_line_spaces(s_lns[1])
                var_decs = indent_by_newline(var_decs, spaces,' ')
                delta = line_deltas[key[0][0]]

                start = ln[:start_loc[1]-1 + delta]
                end = ln[end_loc[1]+1+delta:]
                middle = val[1]
                spaces = get_line_spaces(ln)
                line_change = f"{start}{middle}{end}"

                # add var decs to s_lns
                s_lns[2] = line_change
                s_lns[1] = f"{var_decs}{s_lns[1]}"

                # add line change to s_lns
                line_deltas[key[0][0]] = len(line_change) - orig_len
                lns[start_loc[0]-1] = "\n".join(s_lns)

        #if multi-line we need to compress the functioncall line to 1
        else:
            s = start_loc[0]-1
            e = end_loc[0]-1
            middle = val[1]
            ln = lns[start_loc[0]-1]
            start = ln[:start_loc[1]-1]
            spaces = get_line_spaces(ln)
            var_decs = indent_by_newline(var_decs, spaces, tab)
            ln = lns[end_loc[0]-1]
            end = ln[end_loc[1]+1:]
            for i in range(s+1,e):
                #remove the newlines if multi-line function call
                lns[i] = ""
            #kill the last line since it's now part of variable "end"
            lns[e] = ""
            lns[s] = f"{spaces}{{\n{var_decs}{tab}{start}{middle}{end}{spaces}}}\n"
    return "".join(lns)

#Used for getting the edited/new lines in aligned with surrounding text
def get_line_spaces(ln):
    spaces = len(ln) - len(ln.strip()) - 1
    return  chr(32) * spaces

def indent_by_newline(lns, spcs, tab):
    lns = lns.split('\n')
    lns = lns[:-1]
    rt = ""
    for l in lns:
        rt += tab + spcs + l + "\n"
    return rt

def gen_new_vars(old_vars,num):
    #base for a temporary local variable
    base = "tlv"
    i = 1
    rv = []
    while True:
        nv = f"{base}{i}"
        if nv not in old_vars:
            rv.append(nv)
        if len(rv) == num:
            #flip these so that when I pop them they appear in order
            rv.reverse()
            return rv
        i += 1

#This is for when you have multiple declarations on one line and at leaset
#of of them get initialized
def single_declarations(ctx):
    rewrite = {}
    decs = find_ctx(ctx, "<class 'CParser.CParser.DeclarationContext'>")
    for d in decs:
        #see which declarations are "compound"
        cmpd = find_ctx(d, "<class 'CParser.CParser.InitDeclaratorContext'>")
        if cmpd == [] :
            #print("No initializer+declarations found")
            pass
        else:
            #figure out the arguments.
            try:
                cc = d.getChild(1).getChildCount()
                if  cc > 1:
                    #we are with more than one declaration and one is initialized
                    typ = d.getChild(0).getText()
                    typ = get_string2(typ)
                    all_vars = [d.getChild(1).getChild(x).getText() for x in range(cc) if d.getChild(1).getChild(x).getText() != ',']
                else:
                    #if here we don't have more than one variable in the
                    #declaration and expand_decs will get it
                    continue
                #line_num - 1 cause I think it's not 0 indexed
                rs = ""
                if len(all_vars) > 1:
                    #we need to see if the type ends with a *
                    #if so, remove the * and place it on the first var
                    if typ.endswith("*"):
                        all_vars[0] = f"*{all_vars[0]}" 
                        typ = typ[:-1]
                for a in all_vars:
                    rs+= f"{typ} {a};\n"
                rewrite[(get_line_num(d)-1,get_last_line_num(d))] = rs
            except:
                continue
    return rewrite

#expand any declarations and initilizations that are together
#Input program name
#Outpue dictionary of edits "dict[fistline,lastline] = edit"
#limiting to declarations in functions.
def expand_decs(ctx):
    rewrite = {}
    fns = get_functions(ctx)
    for f in fns:
        decs = find_ctx(f, "<class 'CParser.CParser.DeclarationContext'>")
        for d in decs:
            #see which declarations are "compound"
            cmpd = find_ctx(d, "<class 'CParser.CParser.InitDeclaratorContext'>")
            if (cmpd == []) or  ('=' not in d.getText()):
                pass
                #print("No initializer+declarations found")
            else:
                if ("const" in d.getText() or "char*" in d.getText()):
                    #Here if we have a const that can't be broken up
                    typ = d.getChild(0).getText()
                    stmt = d.getChild(1).getText()
                    typ = fix_type(typ)
                    lhs = get_string2(d.getChild(1).getChild(0).getChild(0))
                    rhs = get_string2(d.getChild(1).getChild(0).getChild(2))
                    if rhs.startswith("("):
                        #fix this later to get everything between () then remake rhs
                        rhs = fix_type(rhs)
                    #print(f"typ={typ},stmt={stmt},lhs={lhs},rhs={rhs}")
                    #This is to make sure we don't have a char array on the rhs
                    #if so we need to make sure to hit the else.
                    ts =  [x[:x.find('[')] for x in get_all_vars(f, False) if '[' in x]
                    #First if is for char*'s that are in the code and I shouldn't minipulate
                    if "char*" in typ and "const" not in typ and not rhs.startswith('"'):
                        rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ} {lhs};\n {lhs} = {rhs};\n"
                    else:
                        if "char*" in typ and rhs not in ts and rhs.startswith('"'):
                            rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ.replace('char*','char')} {lhs}[] = {rhs};\n"
                            #print(f"if:{typ.replace('char*','char')} {lhs}[] = {rhs};\n")
                            #print(f"{d.getText()}")
                        else:
                            #this is an attempt to pass lines that I should not need to chage
                            #example instantiating function pointers
                            rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ} {lhs} = {rhs};\n"
                            #print(f"{typ} {lhs} = {rhs};\n")
                else:
                    #figure out the arguments.
                    try:
                        typ = d.getChild(0).getText()
                        stmt = d.getChild(1).getText()
                        var = get_string2(d.getChild(1).getChild(0).getChild(0))
                        rhs = get_string2(d.getChild(1).getChild(0).getChild(2))
                        #trying to fix the way getText handles structs
                        #rhs = fix_rhs(rhs)
                        typ = fix_type(typ)
                        if var.endswith('[ ]') or rhs.startswith('{'):
                            continue
                        #print(f"type = {typ} var = {var};")
                        #print(f"stmt = {stmt};")
                        #print(f"rhs = {rhs};")
                        #print(f"rewrite number {get_line_num(d)-1}")
                        #line_num - 1 cause I think it's not 0 indexed
                        rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ} {var};\n{var} = {rhs};\n"
                    except:
                        continue
    return rewrite

def fix_rhs(stmt):
    if '"' not in stmt and "struct" in stmt:
        return fix_type(stmt)
    return stmt

def gen_dec_changes(cur_prog, rewrite):
    #print(cur_prog)
    #print("----------")
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns[:-1]]
    keys = list(rewrite.keys())
    keys.sort()
    for key in keys:
        #key is a tuple with the first and last line that are going to be
        #overwritten.
        a,b = key
        if lns[a].startswith("#"):
            a += 1
        tb = get_line_spaces(lns[a])
        if a != b:
            #if here we need to just rewrite the lines with nothing
            for x in range(a,b):
                lns[x] = ""
        #this is so we can get the indentation correct
        splt = rewrite[key].split('\n')
        #lns[a] = f"{tb}{splt[0]}\n{tb}{splt[1]}\n"
        for s in splt[:-1]:
            lns[a] += f"{tb}{s}\n"
    #print ("".join(lns))
    return "".join(lns)

def write_new_program(p,prog_name):
    #write the new file
    with open(f"{prog_name}", 'w') as outfile:
        outfile.write(p)

#Other type fixes should go here
#antlr seems to squish things together so if this happesn to you
#just follow the example of the const fix
def fix_type(typ):
    if "const" in typ:
        typ = typ.replace("const", "const ")
    if "register" in typ:
        typ = typ.replace("register", "register ")
    if "signed" in typ:
        typ = typ.replace("signed", "signed ")
    if "static" in typ:
        typ = typ.replace("static", "static ")
    if "unsigned" in typ:
        typ = typ.replace("unsigned", "unsigned ")
    if "longlong" in typ:
        typ = typ.replace("longlong", "long long")
    if "longint" in typ:
        typ = typ.replace("longint", "long int")
    if "shortint" in typ:
        typ = typ.replace("shortint", "short int")
    if "staticint" in typ:
        typ = typ.replace("staticint", "static int")
    if "unsignedint" in typ:
        typ = typ.replace("unsignedint", "unsigned int")
    if "struct" in typ and typ.startswith("struct"):
        typ = typ.replace("struct", "struct ", 1)
    typ = typ.replace("  ", " ")
    return typ

def const(dec):
    """
    types = ["int", "long", "float", "double"]
    for t in types:
        if (t in dec) and ("const" in dec):
            return True
    return False
    """
    if dec.startswith("constchar*"):
        return False
    if "const" in dec:
        return True
    #not technically a const, but a quick way to ignore
    #arrays of characters that are defined like strings
    if '[' in dec and ']' in dec:
        return True
    return False

def de_const(lst):
    for i in range(len(lst)):
        typ = lst[i][0]
        if const(typ):
            lst[i] = typ.replace("const",""),lst[i][1]

def remove_multiline_comments(prog:str):
    mlcmnt_start_re=re.compile(r'(.*)/\*(.*)$')
    mlcmnt_end_re=re.compile(r'\*/(.*)$')
    lines = prog.split("\n")
    comment=[False]
    ol=[]
    for l in lines:
        cmt=mlcmnt_start_re.search(l)
        if cmt:
            l1=cmt.group(1)
            comment=[True]
            l2=cmt.group(2)
            ecmt= mlcmnt_end_re.search(l2)
            if ecmt:
                l1+=ecmt.group(1)
                comment.append(False)
            l=l1
        elif comment[-1]:
            ecmt= mlcmnt_end_re.search(l)
            if ecmt:
                l=ecmt.group(1)
                comment.append(False)
            else:
                l=None
        if l:
            ol.append(l)
    return ol

def preprocess_string(pragmas:dict,prog:str):
    _pragmas=[ x.strip() if '(' not in x else x.split('(',1)[0] for x in pragmas.keys()] if pragmas else []
    _macros=[]
    if pragmas:
        for x in pragmas.keys():
            if '(' in x:
                _macros.append(x.split('(',1)[0])
    if not pragmas:
        pragmas=dict()
    _macs='|'.join(list(_macros))
    _prags='|'.join(list(_pragmas))
    #print(f"[PRAGMAS] {_macs}")
    pragma_re = None
    macro_re = None
    if len(_macros)>0:
        macro_re=re.compile(r'\b('+_macs+r")\b")
    if len(_pragmas)>0:
        pragma_re=re.compile(r'\b('+_prags+r")\b")
    # note from pdr: there are also #if defined \((\S+)\) LOGICAL , but omitting for simplicity
    positive_re=re.compile(r'^\s*#\s*(if|ifdef|elif)\s+(\w+)')
    negative_re=re.compile(r'^\s*#\s*ifndef\s+(\w+)')
    undef_re=re.compile(r'^\s*#\s*undef\s+(\w+)')
    next_re=re.compile(r'^\s*#\s*else')
    end_re=re.compile(r'^\s*#\s*endif')
    define_re=re.compile(r'^\s*#\s*define\s+(.*)')
    macrofn_re=re.compile(r'^(\w+)(\(.*\))(.*)')
    macrofndef_re=re.compile(r'^(\w+)(\([^\(]*\))(.*)')

    lines = remove_multiline_comments(prog)
    ol=list()
    capture_next,in_cascade,captured,append_to_define=(False,False,False,False)
    cur_define=None
    cur_value=None
    new_pragma=dict()
    for l in lines:
        #print(f"[LINE] '{l}'")
        start=False
        p=positive_re.search(l)
        n=negative_re.search(l)
        el=next_re.search(l)
        und=undef_re.search(l)
        end=end_re.search(l)
        define=define_re.search(l)
        mac=macro_re.search(l) if macro_re else None
        
        if p:
            start=True
            in_cascade=True
            capture_next=False
            #print(f"[positive] {p.group(1)} {p.group(2)} ")
            value=p.group(2)
            if value in _pragmas:
                #print(f"{value} = {pragmas[value]} [{type(pragmas[value])}]")
                if pragmas[p.group(2)]:
                    #print(f"[IFDEF] START CAPTURING POSITIVE: {l}")
                    capture_next=True
                    captured=True
                else:
                    #print(f"[IFDEF] NOT CAPTURING POSITIVE: {l}")
                    pass
        elif n:
            #print(f"[HERE] NEGATIVE {n.group(1)}")
            start=True
            in_cascade=True
            capture_next=False
            if (n.group(1) in _pragmas and not pragmas[n.group(1)]) or (n.group(1) not in _pragmas):
                #print(f"{n.group(1)} = {pragmas.get(n.group(1),None)} [{type(pragmas.get(n.group(1),None))}]")
                #print(f"[IFNDEF] START CAPTURING NEGATIVE: {l}")
                capture_next=True
                captured=True
            else:
                #print(f"[IFNDEF] NOT CAPTURING NEGATIVE: {l}")
                pass
        elif el:
            start=True
            capture_next=False
            if in_cascade and not captured:
                #print(f"[ELSE] START CAPTURING ELSE: {l}")
                capture_next=True
                captured=True
            else:
                #print(f"[ELSE] NOT CAPTURING ELSE: {l}")
                pass
        elif end:
            #print(f"[ENDIF] STOP CAPTURING : {l}")
            start=True
            capture_next=False
            in_cascade=False
            captured=False
        elif und:
            val=und.group(1)
            pragmas[val]=False
        elif not start and (not in_cascade or capture_next):
            if define:
                val=define.group(1).strip()
                macro=macrofndef_re.search(val)
                # #define xyz(a,b,c) \
                #   #1 : xyz 
                #   #2 : (a,b,c)
                #   #3 :  \
    
                macnm,params,rest=(None,None,None)
                if macro:
                    macnm=macro.group(1)
                    params=macro.group(2)
                    rest=macro.group(3)
                    _macros.append(macnm)
                    if len(_macs)<=1:
                        _macs=macnm
                    else:
                        _macs+=f"|{macnm}"
                    macro_re=re.compile(r'\b('+_macs+r")\b")
                else:
                    vals=val.split('\s')
                    macnm=vals[0].strip()
                    if len(vals)>1:
                        rest=" ".join(vals[1:])
    
                if rest and rest[-1]=='\\':
                    append_to_define=True
                    rest=rest[:-1]
                else:
                    append_to_define=False
    
                cur_define=[macnm,params,rest]
                if rest:
                    cur_value=rest
                else:
                    if append_to_define:
                        cur_value="" 
                    else:
                        cur_value=True
    
                if cur_define[0] not in _pragmas:
                    _pragmas.append(cur_define[0])
                    _prags='|'+cur_define[0]
                    try:
                        pragma_re=re.compile(r'\b('+_prags+r")\b")
                    except Exception as e:
                        print(f"[preprocess_string] cur_define => {cur_define}")
                        raise(e)
                
                if not append_to_define:
                    d=f"{cur_define[0]}{cur_define[1]}" if cur_define[1] else cur_define[0]
                    pragmas[d.strip()]=cur_value
                    
                #print(f"[PRAGMA] New pragma {cur_define} => {new_pragma[cur_define]}")
            elif append_to_define:
                val=l
                if val[-1]!='\\':
                    append_to_define=False
                else:
                    val=val[:-1]
                cur_value +=val
                if not append_to_define:
                    d=f"{cur_define[0]}{cur_define[1]}" if cur_define[1] else cur_define[0]
                    pragmas[d.strip()]=cur_value
            elif mac:
                #print(f"[Found macro] {mac.group(1)} {mac.span(1)}")
                macro_dict={key:val for key,val in pragmas.items() if key.startswith(mac.group(1)) }
                k_pragmas=list(macro_dict.keys())
                if len(k_pragmas)<1 and mac.group(1):
                    print("[WARNING!] we have an unmatched pragma!")
                else:
                    #print(f"[Found pragma] {macro_dict} {k_pragmas}\n^^<= {mac.group(1)}\n LINE ==> ['{l}']")
                    span=mac.span(1)
                    e=span[1]
                    #print(f"[params] {l[span[0]:e]} => {l[0:span[0]]} | {l[span[0]:span[1]]}  | {l[span[1]:]}")
                    char=l[e];e+=1
                    params=char
                    p_list=[]
                    index=None
                    open_b=0
                    close_b=0
                    if char=='(':
                        open_b=1
                        index=e-1
                    while(open_b!=close_b) and (open_b!=0):
                        #print(f"[params] {params}")
                        char=l[e];e+=1
                        if char == ',' :
                            if open_b==close_b+1:
                                #print(f"[maybe found it] {l[index+1:e-1]}")
                                p_list.append(l[index+1:e-1])
                                index=e
                        elif char == '(':
                            open_b+=1
                        elif char == ')':
                            close_b+=1
                            if open_b==close_b:
                                #print(f"[maybe found it] {l[index+1:e-1]}")
                                p_list.append(l[index+1:e-1])
                                index=e
                        params+=char
                    # found full parameters
                    substring=(span[0],e)
                    mname,mparams,mpars=(None,None,None)
                    index=None
                    for i in k_pragmas:
                        mfn=macrofndef_re.search(i)
                        if mfn:
                            mname=mfn.group(1)
                            mparams=re.sub('[\(\)]','',mfn.group(2))
                            mpars=mparams.split(',')
                            #print(f"mfn: {i}\nmname: {mname}\nmparams: {mparams}")
                            if len(mpars)==len(p_list):
                                index=i
                                break
                    new_string=macro_dict[i]
                    #print(f"------")
                    #print(f"mfn: {i}\nmname: {mname}\nmparams: {mparams}\nnew_string: {new_string}")
                    for i,m in enumerate(mpars):
                        #print(f"m:{m} p_list:{p_list} ==> l:{l} \nmacroname:{mname}\nmacroparams:{mparams}\nnew_string:{new_string}")
                        nstring=re.sub(r'\b'+m.strip()+r'\b',p_list[i],new_string)
                        #print(f"'{m}' => '{p_list[i]}' \n{new_string} => {nstring}")
                        new_string=nstring
    
                    #macrofn_re=re.compile(r'^(\w+)(\(.*\))(.*)')
                    oldstring=l
                    l=l[0:substring[0]]+new_string+l[substring[1]:]
                    #print(f"[Old string] {oldstring}")
                    #print(f"[new string] {l}")
            

        if not start and (not in_cascade or capture_next):
            # continue for every line
            ol.append(l)


            if capture_next:
                captured=True
    
    pragmas.update(new_pragma)
    return ol,pragmas
            


def preprocess(pragmas:dict,inf:str,outf:str):

    pgrm=None
    with open(inf,'r') as _in:
        pgrm=_in.read()

    ol,updated_pragmas = preprocess_string(pragmas, pgrm)

    with open(outf,'w') as _out:
        for i in ol:
            _out.write(f"{i}\n")
    return updated_pragmas

if __name__ == "__main__":
    main()

