#! /usr/bin/env python
import sys
from antlr4 import *
from CLexer import CLexer
from CParser import CParser
from CListener import CListener
import linked_list
import inspect
import codecs

debug=False
#This program assumes that C.g4 has been used to create
#The parser files CLexer.py Clistener.py and Cparser.py
#see /Documents/work/sefcom/gitpatch/antlr.md for more info
def main():
    """
    parser,tree = get_tree_from_file('test.c')
    print(tree.toStringTree(recog=parser))
    printer = KeyPrinter()
    walker = ParseTreeWalker()
    walker.walk(printer, tree)
    """
    if False:
        test_functs()
        args = get_func_args_from_inp("test_files/test.c", "simple_func",'file')
        print(args)
    #p,t =get_tree_from_file("test_files/tmp_test1.c")
    p,t =get_tree_from_file("test_files/test.c")
    print_ctx_bfs(t,"help")
    get_function_info(functions=get_functions(t),global_vars=[])

    """
    for key,members in inspect.getmembers(ctx):
        print(f"key = {key}\nmember={members}")
    """
class KeyPrinter(CListener):
    def enterSelectionStatement(self, ctx):
        print(f"Enter Selection Statement\n{ctx.getText()}")
        pass
    def enterFunctionDefinition(self,ctx):
        print("Found function: '"+str(ctx.declarator().directDeclarator().directDeclarator().Identifier())+"'")
        print(f"Function content {self.function_content}")
        print ("Looking for '"+self.function+"'")
        if str(ctx.declarator().directDeclarator().directDeclarator().Identifier())==self.function:
            print("Found it!  "+self.function)
            self.enable_dumping=True

def dprint(instr,flush=False):
    if debug:
        print(instr,flush=flush)


def get_tree(inp):
    lexer = CLexer(inp)
    stream = CommonTokenStream(lexer)
    stream.fill()
    parser = CParser(stream)
    #compilationUnit is the "base case" for the grammer described
    #in C.g4
    tree = parser.compilationUnit()
    return parser,tree

def get_tree_from_file(file_name):
    inp = FileStream(file_name)
    return get_tree(inp)

def get_tree_from_string(inp):
    inp = InputStream(inp)
    return get_tree(inp)

def print_ctx_bfs(tree,outf):
    q = linked_list.ll()
    #get first set of children
    q.push_list(list(tree.getChildren()))
    #go through all children breadth first
    txt = ""
    while q.length > 0 :
        e = q.dequeue()
        txt += f"Text={e.getText()}\nType={type(e)}\n"
        txt += f"Child Count = {e.getChildCount()}\n"
        if e.getChildCount()>0:
            for i,c in enumerate(list(e.getChildren())):
                txt+=f"{i} : {type(c)} [{c.getText()}]\n"
        txt += "-------\n"
        if e.getChildCount() != 0:
            q.push_list(list(e.getChildren()))
    with open(outf, 'w') as outfile:
        outfile.write(txt)
    """
    outfile = open(outf, 'w')
    outfile.write(txt)
    """

#get all types of ctx
#use to find functions or conditional statements
def find_ctx(tree,ctx,screen=None):
    q = []
    #get first set of children
    pushq(q, list(tree.getChildren()))
    #go through all children breadth first
    r = []
    while q != []:
        e = popq(q)
        if screen and type(e) in screen:
            continue
        t = type(e)
        if str(t) == ctx:
            r.append(e)
        if e.getChildCount() != 0:
            pushq(q,list(e.getChildren()))
    return r

#Input: a functionDefinitionContext
#Output: the argument names
def get_func_name(fctx):
    return fctx.declarator().getChild(0).getChild(0).getText()

def find_multictx_with_scope(tree,multctx,screen=None,ignore_nodes=None,okay_subscope=None):
    if not tree:
        return None
    q = []
    #get first set of children
    pushq(q, list(tree.getChildren()))
    #go through all children breadth first
    txt = ""
    r = []
    start_scope=type(tree)
    check_scope=any([((screen!=None) and (start_scope in screen)), (okay_subscope!=None)])
    screen_me=screen
    if check_scope:
        if not screen_me:
            screen_me=[]
        screen_me+=okay_subscope
    dprint(f"scope info: start = {start_scope}, check_scope = {check_scope}")

    while q != []:
        e = popq(q)
        if (check_scope and okay_subscope and type(e) in okay_subscope):
            check_scope=False
            screen_me+=okay_subscope
        if (screen_me and type(e) in screen_me) or (ignore_nodes and e in ignore_nodes):
            continue
        txt += f"Text={e.getText()}\nType={type(e)}\n"
        txt += "-------\n"
        t = type(e)
        if t in multctx:
            r.append(e)
        if e.getChildCount() != 0:
            #DFS
            q=list(e.getChildren())+q
            #pushq(q,list(e.getChildren()))
    return r

def find_multictx(tree,multctx,screen=None,ignore_nodes=None,dfs=True,screen_first=True):
    """
        tree = start search here
        multctx = push nodes that matcb any of these type
        screen = dont search below nodes that match these types
        ignore = don't search below nodes that match these nodes
    """
    q = []
    #get first set of children
    pushq(q, list(tree.getChildren()))
    #go through all children breadth first
    txt = ""
    r = []
    while q != []:
        e = popq(q)
        t = type(e)
        if screen_first:
            if (screen and t in screen) or (ignore_nodes and e in ignore_nodes):
                continue
            if t in multctx:
                r.append(e)
        else:
            if t in multctx:
                r.append(e)
            if (screen and t in screen) or (ignore_nodes and e in ignore_nodes):
                continue

        if e.getChildCount() != 0:
            #DFS
            if dfs:
                q=list(e.getChildren())+q
            else:
                pushq(q,list(e.getChildren()))
        txt += f"Text={e.getText()}\nType={t}\n"
        txt += "-------\n"
    return r

def get_function_info(functions,global_vars):
    parents=set()
    pscope=dict()
    scope_vars=dict()
    variable_lut=dict()
    for ctx in functions:
        fname=ctx
        fargs=get_func_args_nodes(ctx)
        scope_stack=list()
        scope_vars[fname]=dict()
        dprint(f"Function: {get_func_name(ctx)} ({fargs})",flush=True)
        scope_dict = get_scopes(ctx)
        compound_scope= list([ i for i in list(scope_dict.keys()) if scope_dict[i]['compound']])
        for p in list(compound_scope):
            import copy
            #scopes_[p] = { 'parent':parent, 'children':child_scopes,'ignore':sibs,'scope_stack':ancestors }
            parent_scope=scope_dict[p]['parent']
            if not parent_scope:
                continue
            scope_stack=copy.copy(scope_dict[p]['scope_stack'])
            scope_children=copy.copy(scope_dict[p]['children'])
            ignore_sibs=copy.copy(scope_dict[p]['ignore'])
            variables=copy.copy(global_vars) if global_vars else []
            if fargs and len(fargs)>0:
                variables.extend(list(fargs))
            lut=[ (v[1],v[0]) for v in variables ]
            var_lut=dict(lut)
            values=[]
            dprint(f"[get_function_info] SCOPE = ({type(p)}) {get_string2(p)}",flush=True)
            dprint(f"[get_function_info] PARENT SCOPE = ({type(parent_scope)}) {get_string2(parent_scope)}",flush=True)
            dprint(f"[get_function_info] SCOPE CHILDREN ={[get_string2(c) for c in scope_children]}",flush=True)
            #if ignore_sibs and len(ignore_sibs)>0:
            #    print(f"[get_function_info] SCOPE IGNORE SIBS ={[(type(c),get_string2(c)) for c in ignore_sibs]}")
            i=0
            while(len(scope_stack)>0):
                cur=scope_stack.pop()
                dprint(f"[get_func] cur => {type(cur)}")
                #children=[x for x in scope_dict[cur]['children'] if x!=scope_stack[-1] ]
                children=scope_children
                for x in scope_dict[cur]['children']:
                    if len(scope_stack)==0 or x!=scope_stack[-1] :
                        children.append(x)
                dprint(f"current_scope={get_string2(cur)}\nchildren={[get_string2(c) for c in children]}")
                decls,values,variable_lut[cur]=get_decls(cur,children,var_lut,ignore_sibs)
                pscope[cur]={'variables':decls,'values':values,'symbol2type_lut':variable_lut[cur]}
                var_lut=copy.copy(variable_lut[cur])
                
                dprint(f"var_lut: {var_lut.keys()}")
                # get local variable declarations in scope
                variables=pscope[cur]['variables']
                values=pscope[cur]['values']
                i+=1
            dprint(f"last scope : {get_string2(cur)}")
            scope_vars[fname][p]={'variables':variables,'values':values,'symbol2type_lut':var_lut,'parent':parent_scope}

    #print_scope_info(scope_vars)
    return scope_vars

def print_scope_info(scope):
    for fn,fs in scope.items():
        print(get_func_name(fn))
        i=0
        for sn, s in fs.items():
            print("{")
            parent=s['parent'] if s['parent'] else sn
            var_s=s['variables']
            val_s=s['values']
            print(f"/* scope = {get_string2(parent)}*/")
            for x in val_s:
                try:
                    typ,var,varinfo,value=x
                    type_info=typ
                    def_var="i"
                    if value:
                        if value==def_var or value.endswith(f" {def_var}") or value.startswith(f"{def_var} ") \
                        or f" {def_var} " in value:
                                def_var+=def_var
                        if varinfo != "":
                            print("\t{ "+f"{typ} {def_var}{varinfo} = {value}; /* {var} */"+" }") 
                        elif varinfo == "":
                            print("\t{ "+f"{typ} {def_var}{varinfo}; {def_var}= {value}; /* {var} */"+" }") 
                            print(f"loc to put in code = {get_end_loc(parent)}")
                except Exception as e:
                    print(f"Exception with x={x}")
                    print(e)
                    raise
            print("}")
            i+=1

def get_fix_loc_rewrites(scope,def_vars=["i"]):
    rewrites = []
    uniques=[]
    for fn,fs in scope.items():
        i=0
        def_vars = get_all_vars(fn, False)
        strip_array_decs(def_vars)
        for sn, s in fs.items():
            parent=s['parent'] if s['parent'] else sn
            var_s=s['variables']
            val_s=s['values']
            for x in val_s:
                try:
                    type_info,var,varinfo,value=x
                    import re
                    typ=re.sub(r"\bconst\b",r' ',type_info)
                    for def_var in def_vars:
                        info=(typ,def_var,value)
                        if info in uniques:
                            continue
                        else:
                            uniques.append(info)
                        if value:
                            loc = get_end_loc(parent)
                            if value==def_var or value.endswith(f" {def_var}") or value.startswith(f"{def_var} ") \
                            or f" {def_var} " in value:
                                #rewrites.append((f"/* SKIPPED ({typ}) {def_var}{varinfo} - used in assignment '{value}'  */",loc))
                                continue
                            if varinfo != "":
                                rep_str = ("\t{ "+f"{typ} {def_var}{varinfo} = {value}; /* {var} */"+" }") 
                            elif varinfo == "":
                                rep_str = ("\t{ "+f"{typ} {def_var}{varinfo}; {def_var}= {value}; /* {var} */"+" }") 
                            rewrites.append((rep_str,loc))
                except Exception as e:
                    print(f"Exception with x={x}")
                    print(e)
                    raise
            #print("}")
            i+=1
    return rewrites

def strip_array_decs(lst):
    for i in range(len(lst)):
        if '[' in lst[i]:
            lst[i] = lst[i][:lst[i].find('[')]

def get_string2(ctx,ignore_list=None):
    if ctx==None:
        return None
    q=[ctx]
    st=[]
    while len(q)>0:
        node=q.pop()
        if ignore_list and node in ignore_list:
            continue
        if type(node)==tree.Tree.ErrorNodeImpl:
            #print(f"Encountered an error!!!!\n{get_string2(node.parentCtx)}")
            continue
        if type(node)==tree.Tree.TerminalNodeImpl:
            st.append(node.getText())
        else:
            children=list(node.getChildren())
            if children and len(children)>0:
                children.reverse()
                q.extend(children)
    return ' '.join(st)

        
def get_string(ctx):
    return ' '.join([c.parentCtx.getText() for c in find_ctx(ctx,"<class 'antlr4.tree.Tree.TerminalNodeImpl'>")])
    


def get_siblings_to_ignore(pscope):
    siblings=[]
    child=None
    if type(pscope)!=CParser.FunctionDefinitionContext:
        parent=[pscope.parentCtx]
        child=pscope
        while type(parent[-1])!=CParser.ExternalDeclarationContext:
            children=list(parent[-1].getChildren())
            dprint(f"[get_siblings] --------------")
            dprint(f"[get_siblings] current = {type(child)}",flush=True)
            dprint(f"[get_siblings] parent = {type(parent[-1])}",flush=True)
            dprint(f"[get_siblings] parents children = {[type(c) for c in children]}",flush=True)
            if len(children)>=1:
                get=False
                for x in range(0,len(children)):
                    if get:
                        dprint(f"[get_siblings] SIBLING [ {x} ] : type = {type(children[x])}",flush=True)
                        if not siblings:
                            siblings=[]
                        siblings.extend([children[x]])
                    if children[x]==child:
                        get=True
            child=parent[-1]
            parent.append(parent[-1].parentCtx)
        dprint(f"get_siblings_to_ignore -> parents")
        for p in parent:
            dprint(f" -> {type(p)} [{get_string2(p)}]")
        dprint(f"[get_siblings] SIBLINGS => {[type(g) for g in siblings]}")
    return child,siblings
    
def find_parent_scope(scope,num_parents=None):
    dprint(f"[find_parent_scope] START")
    stop=[\
           CParser.FunctionDefinitionContext\
          ]
    scope_mtch= [\
             CParser.IterationStatementContext,\
             CParser.SelectionStatementContext,\
          ]+stop
    cmpd4=[\
            [\
               CParser.CompoundStatementContext,\
               CParser.StatementContext,\
               CParser.BlockItemContext,\
               CParser.BlockItemListContext\
            ]\
          ]
    cmpd2=[\
            [\
               CParser.CompoundStatementContext,\
               CParser.FunctionDefinitionContext\
            ]\
          ]
    cmpd3=[ \
            [\
               CParser.CompoundStatementContext,\
               CParser.StatementContext,\
               CParser.IterationStatementContext\
            ],\
            [\
               CParser.CompoundStatementContext,\
               CParser.StatementContext,\
               CParser.SelectionStatementContext\
            ],\
          ]
    p=[scope]
    typ_p=[type(x) for x in p]
    dprint(f"searching : {typ_p[-1]} {get_string2(p[-1])}")
    scopes_=list()
    l=len(scopes_)
    while type(p[-1]) not in stop:
        if num_parents and num_parents==l:
            break
        p.append(p[-1].parentCtx)
        typ_p.append(type(p[-1]))
        delim="\n\t"

        dprint(f"parents[-4:]: {typ_p[-4:]}")
        if len(p)>=4 and typ_p[-4:] in cmpd4:
            scopes_.append(p[-2])
        elif len(p)>=3 and typ_p[-3:] in cmpd3:
            scopes_.append(p[-1])
        elif len(p)>=2 and typ_p[-2:] in cmpd2:
            scopes_.append(p[-1])
        elif type(p[-1]) in scope_mtch:
            scopes_.append(p[-1])
        if l!=len(scopes_):
            dprint(f"[{l}] : last = {type(scopes_[-1])} ")
            if len(scopes_)>2:
                dprint(f"[{l-1}] : next to last = {type(scopes_[-2])} ")
            l=len(scopes_)
    dprint(f"SCOPES : {scopes_}")
    dprint(f"SCOPE TYPES : {[type(s) for s in scopes_]}")
    dprint(f"[find_parent_scope] DONE")
    return scopes_

    
def find_parent_scope2(scope):
    dprint(f"[find_parent_scope2] {type(scope)}")
    pscope=None
    if scope and type(scope)!=CParser.FunctionDefinitionContext:
        p=[None,None,scope,scope.parentCtx]
        type_p=[None,None,type(scope),type(p[-1])]
        stop_next_child = [\
              CParser.CompoundStatementContext,\
              CParser.IterationStatementContext,CParser.SelectionStatementContext
              ]
        checkme=[\
              CParser.FunctionDefinitionContext,\
            ]+stop_next_child
        standalone_blk=[CParser.CompoundStatementContext,CParser.StatementContext,CParser.BlockItemContext,CParser.BlockItemListContext]
    
        pscope=p[-1]
        dprint(f"\t{type(p[-1])}",flush=True)
        while type(p[-1]) not in checkme:
            dprint(f"\t{type(p[-1])}",flush=True)
            if type_p==standalone_blk: 
                pscope=p[1]
                break
            p=[p[-3],p[-2],p[-1],p[-1].parentCtx]
            type_p=[type_p[-3],type_p[-2],type_p[-1],type(p[-1])]
            pscope=p[-1]

        dprint(f"\n[find_parent_scope2]\nCHILD : {type(scope)} \nPARENT : {type(pscope)}")
    return pscope,None

def str_nodes(t:list):
    for i in range(0,len(t)):
        if t[i] and type(t[i])!=str:
            t[i]=get_string2(t[i])
            
    return tuple(t)

def get_decl_info(vt,found,lut):
    val_t=list()
    str_found=[get_string2(f) for f in found]
    if vt:
        for v in vt:
            type_n,decl_n,value_n=v
            if decl_n in found or decl_n in str_found:
                continue
            declaration=list(decl_n.getChild(0).getChildren())
            decl_info=""
            if len(declaration)>1:
                for i in range(1,len(declaration)):
                    decl_info+=get_string2(declaration[i])
                d=get_string2(declaration[0])
                lut[d]=get_string2(type_n)+" *"
                found.append(declaration[0])
                str_found.append(d)
            lut[get_string2(decl_n)]=type_n
            val_t.extend([str_nodes([type_n,declaration[0],decl_info,value_n])])    
            found.append(decl_n)
            str_found.append(get_string2(decl_n))
    return val_t,found,str_found,lut

def get_decls(ctx,child_ctx,var_lut:dict,ignore_nodes:list):
    #global debug
    #debug=True
    # we don't want to go beyond the current scope
    start=ctx
    #screen_me=[CParser.FunctionDefinitionContext,CParser.IterationStatementContext]
    ignore_me=list(ignore_nodes)+list(child_ctx)

    children=list(start.getChildren())
    while(len(children)==1 and type(start)!=tree.Tree.TerminalNodeImpl):
        try:
            start=children[0].getChild(0)
            if type(start)==tree.Tree.TerminalNodeImpl:
                break
            children=list(start.getChildren())
        except Exception as e:
            print(f"{type(children[0])}")
            print(e)
            raise
    if type(start)==tree.Tree.TerminalNodeImpl:
        start=ctx
    rules_with_comparators=[CParser.RelationalExpressionContext,CParser.EqualityExpressionContext]
    rules_with_assignment=[CParser.InitDeclaratorContext,CParser.AssignmentExpressionContext]
    rules_with_declarations=[CParser.ForDeclarationContext,CParser.DeclarationContext]
    ops=['==','<=','>=','<','>','!=']
    # so I needed a function that enables evaluation of the first okay_scope_changes follows screen_me
    # the point is to identify declarations, equality, etc
    a = [p for p in find_multictx(ctx, [tree.Tree.TerminalNodeImpl]+rules_with_declarations,None,ignore_me) \
        if ( type(p)==tree.Tree.TerminalNodeImpl and any([op in p.getText() for op in ops])) or (type(p) in rules_with_declarations) ]
    assigns=[]
    comparisons=[]
    check_these_nodes=list()
    for i in a:
        if type(i)==tree.Tree.TerminalNodeImpl:
            p=i.parentCtx
            ba=(type(p) in rules_with_assignment)
            bc=(type(p) in rules_with_comparators)
            while not ba and not bc:
                p=p.parentCtx
                ba=(type(p) in rules_with_assignment)
                bc=(type(p) in rules_with_comparators)
            if ba:
                check_these_nodes.append(p)
            if bc:
                check_these_nodes.append(p)
        else:
            check_these_nodes.append(i)
    
    #global debug
    #debug=True
    for i,p in enumerate(check_these_nodes):
        dprint(f"check_these_nodes[{i}]: {get_string2(p)}")
    #debug=False
    declarations=list()

    val_t=list()
    found=list()
    str_found=list()
    vardict=dict()
    vars_t=list()
    typs_t=list()
    for d in check_these_nodes:
        chld=list(d.getChildren())
        d____,ignore_siblings=get_siblings_to_ignore(d)
        var_t,typ_t=(None,None)
        l_ignore=ignore_me
        if ignore_siblings:
            if not l_ignore:   
                l_ignore=list()
            l_ignore.extend(ignore_siblings)
        if type(d)==CParser.ForDeclarationContext:
            dprint(f"For declaration: {get_string2(d)}")
            typ=chld[0]
            node=chld[1]
            dec=list(find_multictx(chld[1],[CParser.DeclaratorContext],None,l_ignore))
            f=list()
            for n in find_multictx(node,[CParser.InitDeclaratorContext],None,l_ignore):
                x=list(n.getChildren())
                val=x[2] if len(x)>1 else None
                v=(typ,x[0],val)
                f.append(v)
            var_t=[v for v in dec if v not in found ]
            typ_t=[typ for i in var_t]
            vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
        if type(d)==CParser.DeclarationContext:
            if len(chld) == 3:
                typ=chld[0]
                dec=list(find_multictx(chld[1],[CParser.DeclaratorContext],None,l_ignore))
                f=list()
                if type(chld[1])==CParser.InitDeclaratorListContext:
                    node=chld[1]
                    f=[ (typ,n.getChild(0),n.getChild(2)) for n in find_multictx(node,[CParser.InitDeclaratorContext],None,l_ignore) if n.getChild(0) not in found ]
                else:
                    # type,variable,initial_value
                    f= [(typ,v,None) for v in dec if v not in found]
                var_t=[v for v in dec if v not in found]
                typ_t=[typ for i in var_t]
                vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
            if len(chld) == 2:
                # this is a bug you see when you have 'int a;'
                node=chld[0]
                typ=node.getChild(0)
                var=node.getChild(1)
                # type,variable,initial_value
                f= [ (typ,var,None) ]
                var_t=[var]
                typ_t=[typ]
                vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
        if type(d)==CParser.RelationalExpressionContext or type(d)==CParser.EqualityExpressionContext:
            varlkup1=get_string2(chld[0])
            varlkup2=get_string2(chld[2])
            typ1=var_lut.get(varlkup1,vardict.get(varlkup1,None))
            typ2=var_lut.get(varlkup2,vardict.get(varlkup2,typ1))
            if typ1==None and typ2 == None:
                print(f"[WARNING] Looks like we've hit an unimplemented case for LHS={varlkup1},RHS={varlkup2}")
                print(f"[WARNING] Check this line: {get_string2(d)} ")
                print(f"[VERIFY] {var_lut.items()}")
                print(f"[VERIFY] {vardict.items()}")
                print(f"[WARNING] found: {[get_string2(f) for f in found]} ")
                print(f"[WARNING] SKIPPING ")
                continue
            elif typ1==None:
                typ1=typ2
            if type(typ1)==str:
                typ1_t=typ1
            else:
                typ1_t=get_string2(typ1)
            if type(typ2)==str:
                typ2_t=typ2
            else:
                typ2_t=get_string2(typ2)

            val=get_string2(chld[2])
            # type,variable,initial_value
            f= [ (typ1,chld[0],chld[2]), (typ2,chld[2],chld[0]) ]
            var_t = [get_string2(chld[0]),get_string2(chld[2])]
            typ_t = [typ1_t,typ2_t]
            vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
            
        if type(d)==CParser.InitDeclaratorContext:
            # guaranteed to have 3 children
            varlkup=get_string2(chld[0])
            typ=var_lut.get(varlkup,vardict.get(varlkup,"int"))
            typ_v=typ if type(typ)==str else get_string2(typ)
            val=get_string2(chld[2])
            # type,variable,initial_value
            f= [ (typ,chld[0],chld[2]) ]
            for x in f:
                str_x=get_string2(x[1])
                fnd=(str_x in str_found)
                dprint(f"5: {get_string2(x[0])},{get_string2(x[1])},{get_string2(x[2])} [FOUND={fnd}]")
                dprint(f"found = {[get_string2(ii) for ii in found]}")
            var_t = [ get_string2(chld[0]) ]
            typ_t = [ typ ]
            vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
        if type(d)==CParser.AssignmentExpressionContext:
            if len(chld)==3:
                varlkup=get_string2(chld[0])
                typ=var_lut.get(varlkup,vardict.get(varlkup,None))
                if typ and type(typ)==str:
                   typ_v=typ
                elif typ:
                   typ_v=get_string2(typ)
                else:
                   typ_v="int" # default!
                val=get_string2(chld[2])
                # type,variable,initial_value
                f= [ (typ,chld[0],chld[2]) ]
                for x in f:
                    a,b,c=x
                    if type(a)!=str:
                      a=get_string2(a)
                    b=get_string2(b)
                    c=get_string2(c)
                    fnd=(b in str_found)
                    dprint(f"6: {a},{b},{c} [FOUND={fnd}]")
                    dprint(f"found = {[get_string2(ii) for ii in found]}")
                var_t = [ get_string2(chld[0]) ]
                typ_t = [ typ ]
                vt,found,str_found,var_lut=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
            #elif len(chld)==1:
            #    pass

            else:
                pass

        if not var_t:
            pass
        else:
            vars_t.extend(var_t) 
            typs_t.extend(typ_t)
            for i,v in enumerate(var_t):
                v_=v
                if type(v) != str:
                    v_=get_string2(v)
                vardict[v_]=typ_t[i]

    rs = [ get_string2(v) if type(v)!=str else v for v in vars_t ]
    ts = [ get_string2(t) if type(t)!=str else t for t in typs_t ]
    declarations.extend(list(zip(ts, rs)))

    debug=False
    return declarations,val_t,var_lut
            
def get_scopes(node):
    scopes_=dict()
    child_scopes=dict()
    okay_scope_changes=[CParser.CompoundStatementContext]
    stop_scope = [\
          CParser.IterationStatementContext,\
          CParser.SelectionStatementContext\
          ]
    no_subscope=okay_scope_changes+stop_scope

    node2ancestors=dict()
    node2parent=dict()
    node2children=dict()

    compound_scopes = find_multictx(node,okay_scope_changes)
    parent=None
    ancestors=None
    p_=find_parent_scope(node)
    if p_ and len(p_)>0:
        parent=p_[0]
        ancestors=p_
    # def find_multictx(tree,multctx,screen=None,ignore_nodes=None,dfs=True,screen_first=True):
    child_scopes=find_multictx(node,okay_scope_changes,okay_scope_changes,None,True,False)
    node2parent[node]=parent
    node2ancestors[node]=ancestors
    node2children[node]=child_scopes
    if type(node)==CParser.FunctionDefinitionContext:
        dprint(f"start node : children = {[(type(c),get_string2(c)) for c in node2children[node]]}")
        pass

    scopes=[node]+compound_scopes
    scopes.reverse()
    resolved_scopes=list()
    compound=dict()

    parents=list()
    for i,c in enumerate(compound_scopes):
        p_i=find_parent_scope(c)
        node2ancestors[c]=p_i
        node2parent[c]=p_i[0]
        if p_i[0] not in compound_scopes:
            parents.append(p_i[0])
    for i,c in enumerate(parents):
        p_i=find_parent_scope(c)
        node2ancestors[c]=p_i
        if p_i and len(p_i)>0:
            node2parent[c]=p_i[0]
        else:
            node2parent[c]=None
    for i,c in enumerate(scopes+parents):
        compound=(c in scopes)
        pc=node2parent.get(c,None)

        # when the 5th parameter is False -> BFS, else DFS
        # when the last/6th parameter is False [if true, then we check (2) then (1)]
        # (1)we check to see if the node type is in the list of multctx [if so, add it to return list]
        # (2)then if its type is in the screen list or the node is in ignore nodes list, don't process any of its children
        c_i=list(find_multictx(c,okay_scope_changes,okay_scope_changes,None,True,False))
        cp_i=[node2parent[c_ii] for c_ii in c_i if c_ii != c ]
        node2children[c]=cp_i
        

    for i,p in enumerate(scopes+parents):
        compound=(p in scopes)
        child_scopes=node2children[p]
        parent=node2parent[p]
        ancestors=node2ancestors[p]
        t=(type(parent),type(p))

        sibs=None
        if t[0] in [CParser.ExternalDeclarationContext]:
            pass
        else:
            parents.append(parent)
        if t[0] in [CParser.BlockItemContext,CParser.FunctionDefinitionContext]:
            pass
            
        ____,sibs=list(get_siblings_to_ignore(p))
        scopes_[p] = { 'parent':parent, 'children':child_scopes,'ignore':sibs,'scope_stack':ancestors, 'compound':compound }




    #import sys
    #sys.exit(-1)
    return scopes_


    
def get_scopes_old(ctx):
    okay_scope_changes=[CParser.CompoundStatementContext]
    try:
        #ftlc = find_ctx(ctx, "<class 'CParser.CParser.CompoundStatementContext'>")
        ftlc = find_multictx(ctx,okay_scope_changes)
        return ftlc
    except:
        return None

def get_arg_names(ctx):
    try:
        ftlc = find_ctx(ctx, "<class 'CParser.CParser.ParameterTypeListContext'>")
        c = ftlc[0].getChild(0)
        cl = c.children
        cs = [c for c in cl if str(type(c)) != "<class 'antlr4.tree.Tree.TerminalNodeImpl'>"]
        rs = [c.getChild(1).getText() for c in cs]
        return rs
    except:
        return None

#Input: contex of a function
#Output: list of tuples [(type,var_name)]
def get_func_args(ctx):
    try:
        ftlc = find_ctx(ctx, "<class 'CParser.CParser.ParameterTypeListContext'>")
        if len(ftlc) > 0:
            c = ftlc[0].getChild(0)
            cl = c.children
            cs = [c for c in cl if str(type(c)) != "<class 'antlr4.tree.Tree.TerminalNodeImpl'>"]
            rs = [c.getChild(1).getText() for c in cs]
            ts = [c.getChild(0).getText() for c in cs]
            return list(zip(ts, rs))
        else:
            return None
    except:
        return None

#Output: list of tuples [(type'node,var_name)]
def get_func_args_nodes(ctx):
    try:
        ftlc = find_ctx(ctx, "<class 'CParser.CParser.ParameterTypeListContext'>")
        if len(ftlc) > 0:
            c = ftlc[0].getChild(0)
            cl = c.children
            cs = [c for c in cl if str(type(c)) != "<class 'antlr4.tree.Tree.TerminalNodeImpl'>"]
            rs = [c.getChild(1).getText() for c in cs]
            ts = [c.getChild(0) for c in cs]
            return list(zip(ts, rs))
        else:
            return None
    except:
        return None


#if conditions will be '<class 'CParser.CParser.SelectionStatementContext'>
def get_conditionals(ctx):
    ftlc = find_ctx(ctx, "<class 'CParser.CParser.SelectionStatementContext'>")
    return ftlc

def get_functions(ctx):
    return find_ctx(ctx,"<class 'CParser.CParser.FunctionDefinitionContext'>")

def get_function_calls(ctx):
    funcs = find_ctx(ctx, "<class 'CParser.CParser.PostfixExpressionContext'>")
    return [x for x in funcs if x.getChildCount() > 1]

def get_function(ctx, f_name):
    fns = get_functions(ctx)
    for f in fns:
        if get_func_name(f) == f_name:
            return f

def test_functs():
    p,t =get_tree_from_file("test_files/test.c")
    fns = get_functions(t)
    print("Found the following functions")
    for f in fns:
        print(f.getText())
        print(f"all func vars {get_all_vars(f,False)}")
    print_ctx_bfs(fns[0], "tmp2")
    print(get_func_args(fns[0]))
    """
    print("First function has the following conditionals")
    cs = get_conditionals(fns[1])
    for c in cs:
        print(c.getText())
    t = get_tokens_form_ctx(cs[0])
    """
    decs = find_ctx(fns[0], "<class 'CParser.CParser.DeclarationContext'>")
    cmpd = find_ctx(decs[0], "<class 'CParser.CParser.InitDeclaratorContext'>")
    return decs,cmpd

def get_func_args_from_inp(inp, func_name,inp_type):
    if inp_type == "file":
        p,t =get_tree_from_file(inp)
    if inp_type == "c_string":
        p,t =get_tree_from_string(inp)
    fn = get_function(t, func_name)
    return get_arg_names(fn)

#Input: A function context
#Output: List of variables used in the function including function parameters
def get_all_vars(func_ctx, ret_types):
    try:
        r_vars = []
        r_types = []
        #Get function arguments if they exist
        f_args = get_arg_names(func_ctx)
        if f_args != None:
            r_vars.extend(f_args)

        #Get all declarations
        decs = find_ctx(func_ctx, "<class 'CParser.CParser.DeclarationContext'>")
        for d in decs:
                # This works for ints, longs, floats etc
                if d.getChildCount() == 3:
                    r_vars.append(d.getChild(1).getChild(0).getChild(0).getText())
                    #print(d.getChild(1).getChild(0).getChild(0).getText())
                    r_types.append(d.getChild(0).getChild(0).getText())
                #This works for structs
                if d.getChildCount() == 2:
                    if d.getChild(0).getChildCount() == 2:
                        r_vars.append(d.getChild(0).getChild(1).getText())
                    if d.getChild(0).getChildCount() == 3:
                        r_vars.append(d.getChild(0).getChild(2).getText())
                    #r_vars.append(d.getChild(0).getChild(1).getText())
        if ret_types == True:
            return (r_types,r_vars)
        else:
            return r_vars
    except:
        print("Error parsing get_all_vars")
        print(d.getText())
        print(d.getChildCount())
        return None

def get_tokens_form_ctx(ctx):
    #BFS to get all children, may need to DFS just try and print both
    #add every child into queue
    #put every child that is terminal in array
    #figure out all the tokens we want to print (will be int)
    stack = []
    tokens = []
    stack.extend(list(ctx.getChildren()))
    while stack != []:
        s = stack.pop()
        tokens.extend(all_tokens(s))
        if s.getChildCount() > 0:
            stack.extend(list(s.getChildren()))
    for t in tokens:
        print(t)
    return tokens

def get_line_num(ctx):
    c = ctx
    while c.getChildCount() > 0:
        c = c.getChild(0)
    #print (f"start symbol line {c.getSymbol().line}")
    return c.getSymbol().line

def get_last_line_num(ctx):
    c = ctx
    while c.getChildCount() > 0:
        c = c.getChild(c.getChildCount()-1)
    #print (f"end symbol line {c.getSymbol().line}")
    return c.getSymbol().line

def get_start_loc(ctx):
    c = ctx
    while c.getChildCount() > 0:
        c = c.getChild(0)
    return c.getSymbol().line, c.getSymbol().column+1

def get_end_loc(ctx):
    c = ctx
    while c.getChildCount() > 0:
        c = c.getChild(c.getChildCount()-1)
    return c.getSymbol().line, c.getSymbol().column

def all_tokens(ctx):
    try:
        for i in range(104):
            if ctx.getTokens(i) != []:
                return [ctx]
    except:
        return []
    return []

#This is the quick and dirty way of doing this, but is not going
#to affect the code enough to makem me want to make it faster
#if someone gets bored we can do this with a linked list so we
#don't have to reverse the list two times.
def pushq(q, lst):
    return q.extend(lst)

def popq(q):
    q.reverse()
    r = q.pop()
    q.reverse()
    return r

#Input a file with a list of .c files to search functions for
#Output a dictionary of functions and their arguments
def parse_pre_process(inf):
    #return dictionary
    ret_d = {}
    ret_d2 = {}
    with open(inf, 'r') as infile:
        cnts = infile.readlines()
    #get rid of the new lines
    cnts = [x.strip() for x in cnts]
    for c in cnts:
        #read all the files and pull out the functions from each file to return
        p,t = get_tree_from_file(c)
        fns = get_functions(t)
        for f in fns:
            ret_d[get_func_name(f)] = get_func_args(f)
            ret_d2[get_func_name(f)] = f.getChild(0).getText()
    return ret_d,ret_d2

if __name__ == "__main__":
    main()

