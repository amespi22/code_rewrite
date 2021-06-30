#! /usr/bin/env python
from antlr_funcs import *
import argparse
import sys

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
    if pre_process != "":
        #This means we have a file to parse
        #File should have a new line for each file to parse
        #Files named should be .c files
        funcs_and_args,funcs_and_rts = parse_pre_process(pre_process)
    else:
        funcs_and_rts = {}
        funcs_and_args = {}

    #original program
    cur_pro = ""
    with open(prog_name, 'r') as infile:
        cur_pro = infile.read()

    #get the dictionary that maps line numbers with the re-write
    p,t = get_tree_from_file(prog_name)

    #loop to run all code transformations
    #order matters, don't re-arrange
    change_funcs = [expand_if_else,single_declarations, expand_decs,expand_func_args,expand_decs]
    apply_changes = [gen_if_changes,gen_dec_changes, gen_dec_changes,gen_func_changes,gen_dec_changes]
    for i in range(len(change_funcs)):
        if i != 0:
            p,t = get_tree_from_string(cur_pro)
        rewrite = change_funcs[i](t)
        cur_pro = apply_changes[i](cur_pro, rewrite)

    #FIX-INGREDIENTS
    p,t = get_tree_from_string(cur_pro)
    scope_vars = get_function_info(functions=get_functions(t),global_vars=[])
    fix_loc_rewrites = get_fix_loc_rewrites(scope_vars)
    cur_pro = gen_fix_loc_changes(cur_pro, fix_loc_rewrites)

    #write out the new program
    write_new_program(cur_pro, out_name)

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
                    rewrites[start_loc, end_loc] = (f"{funcs_and_rts[f_name]} {dec} = {c.getText()};", dec)
    return rewrites

def gen_if_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    for key,val in rewrite.items():
        start_loc, end_loc = key
        func_call,var_use = val
        #if the start and end loc lines are the same
        if key[0][0] == key[1][0]:
            ln = lns[start_loc[0]-1]
            start = ln[:start_loc[1]-1]
            end = ln[end_loc[1]+1:]
            middle = var_use
            spaces = get_line_spaces(ln)
            line_change = f"{start}{middle}{end}"
            lns[start_loc[0]-1] = f"{spaces}{func_call}\n{line_change}"
        #if multi-line we need to compress the functioncall line to 1
        else:
            print("You should really have done this")
    return "".join(lns)

def expand_func_args(ctx):
    #find all functions, record their names and paramaters
    fns = get_functions(ctx)
    rewrites = {}
    #This gives us all functions in the file and it's args
    for f in fns:
        funcs_and_args[get_func_name(f)] = get_func_args(f)
    #for each function find all <class 'CParser.CParser.PostfixExpressionContext'>
    for f in fns:
        new_vars = []
        all_types, all_vars = get_all_vars(f,True)
        pecs = find_ctx(f, "<class 'CParser.CParser.PostfixExpressionContext'>")
        pecs = [p for p in pecs if p.getChildCount() > 1]
        try:
            for p in pecs:
                f_name = p.getChild(0).getText()
                if f_name in funcs_and_args:
                    #print(f"function {f_name} is present with args {p.getChild(2).getText()}")
                    func_args = [c for c in p.getChild(2).getText().split(',')]
                    if func_args == [')']:
                        continue
                    #replace index in function arguments
                    rep = []
                    j = 0
                    #Find indexes to replace.
                    #I do this in two passes so I can create
                    #all the new variables in one shot
                    for i in func_args:
                        if i not in all_vars:
                            rep.append(j)
                        j += 1
                    # only here if we have 1 or more arguments to pull out
                    if len(rep) > 0:
                        start_loc = get_start_loc(p)
                        end_loc = get_end_loc(p)
                        #print(f"start location {start_loc} end location = {end_loc}")
                        #get new variables to use
                        r_vars = gen_new_vars(new_vars + all_vars, len(rep))
                        #add to the list of all variables so they are not used
                        #again in the same function on another call
                        #all_vars.extend(r_vars)
                        fun_arg_types = funcs_and_args[f_name]

                        #added this cause we don't need functions that take
                        #const args to make the varialbes we send them const
                        de_const(fun_arg_types)

                        #This happens in nested situations and for now
                        #I ignore it silently
                        if len(func_args) > len(fun_arg_types):
                            continue

                        new_arg_string = f"{f_name}("
                        new_var_dec = ""
                        for i in range(len(func_args)):
                            if i in rep:
                                #replace that variable
                                v = r_vars.pop()
                                new_var_dec += f"{fun_arg_types[i][0]} {v} = {func_args[i]};\n"
                                new_arg_string += f"{v},"
                            else:
                                #use what was already there
                                new_arg_string += f"{func_args[i]},"
                        #print (new_var_dec[:-1])
                        #print (new_arg_string[:-1]+')')
                        rewrites[start_loc,end_loc] = (new_var_dec,new_arg_string[:-1]+')')
        except:
            continue

    #record the changes needed to re-write the code
    return rewrites

def gen_func_changes(cur_prog, rewrite):
    lns = cur_prog.split('\n')
    lns = [x+"\n" for x in lns]
    lns = lns[:-1]
    tab = chr(32) * 4
    for key,val in rewrite.items():
        start_loc, end_loc = key
        var_decs,func_call = val
        #if the start and end loc lines are the same
        if key[0][0] == key[1][0]:
            ln = lns[start_loc[0]-1]
            start = ln[:start_loc[1]-1]
            end = ln[end_loc[1]+1:]
            middle = val[1]
            spaces = get_line_spaces(ln)
            var_decs = indent_by_newline(var_decs, spaces, tab)
            line_change = f"{tab}{start}{middle}{end}"
            lns[start_loc[0]-1] = f"{spaces}{{\n{var_decs}{line_change}{spaces}}}\n"
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
                    all_vars = [d.getChild(1).getChild(x).getText() for x in range(cc) if d.getChild(1).getChild(x).getText() != ',']
                else:
                    #if here we don't have more than one variable in the
                    #declaration and expand_decs will get it
                    continue
                #line_num - 1 cause I think it's not 0 indexed
                rs = ""
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
                if (const(d.getText())):
                    #Here if we have a const that can't be broken up
                    typ = d.getChild(0).getText()
                    stmt = d.getChild(1).getText()
                    typ = fix_type(typ)
                    rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ} {stmt};\n"
                else:
                    #figure out the arguments.
                    try:
                        typ = d.getChild(0).getText()
                        stmt = d.getChild(1).getText()
                        var = d.getChild(1).getChild(0).getChild(0).getText()
                        typ = fix_type(typ)
                        #print(f"{typ} {var};")
                        #print(f"{stmt};")
                        #line_num - 1 cause I think it's not 0 indexed
                        rewrite[(get_line_num(d)-1,get_last_line_num(d))] = f"{typ} {var};\n{stmt};\n"
                    except:
                        continue
    return rewrite

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
    if "signed" in typ:
        typ = typ.replace("signed", "signed ")
    if "unsigned" in typ:
        typ = typ.replace("unsigned", "unsigned ")
    if "longlong" in typ:
        typ = typ.replace("longlong", "long long")
    if "longint" in typ:
        typ = typ.replace("longint", "long int")
    if "shortint" in typ:
        typ = typ.replace("shortint", "short int")
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


if __name__ == "__main__":
    main()

