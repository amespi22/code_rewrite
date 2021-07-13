#! /usr/bin/env python
import sys

from antlr4 import *
from CLexer import CLexer
from CParser import CParser
from CListener import CListener
import linked_list
import inspect
import codecs
import copy
import json

debug=(False,False) # [0] print debug messages ; [1] generate debug log from debug messages
gbl_debug_msg=["",0,open("debug.log","w") if debug[1] else None,debug[1] ]
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
    p,t =get_tree_from_file("test_files/service.i")
    exit()
    #p,t =get_tree_from_file("new_code_expand.c")
    print_ctx_bfs(t,"help")
    printer=ScopeListener()
    walker = ParseTreeWalker()
    walker.walk(printer,t)

    #for i,k in printer.scopes.items():
    #    print(f"{type(i)} => {get_string2(i)}")
    #    print(f"\t {k['func_ctx']}")
    #    print(f"\t {type(k['parent'])} => {get_string2(k['parent'])}")

    x=get_function_info(functions=get_functions(t),fscope=printer.scopes)
    print_scope_info(x)

    """
    for key,members in inspect.getmembers(ctx):
        print(f"key = {key}\nmember={members}")
    """
def siblings(current):
    parent=current.parentCtx
    family=list(parent.getChildren())
    older=None
    younger=None
    if len(family)>0:
        for i in range(0,len(family)):
            if current==family[i]:
                break
        if i!=0:
            younger=family[0:i]
        if i!=len(family)-1:
            older=family[i+1:]
    return younger,older

class ScopeListener(CListener):
    cur_scopes=[ [], ]
    resolved=list()
    scopes=dict()
    # keys: k, list of nodes that are valid_parent_scopes
    #       k['ancestors'] : list of parent nodes
    #       k['ignore_nodes'] : list of nodes that should not be used to evaluate for variables declaration
    #       k['pscopes'] : list of preceding scope noes
    #       k['parent'] : immediate parent node
    #       k['children'] : children nodes
    #       k['func_ctx'] : function context
    valid_parent_scopes=[\
        CParser.CompoundStatementContext,\
        CParser.IterationStatementContext,\
        CParser.SelectionStatementContext,\
        CParser.FunctionDefinitionContext\
        ]
    current_fn_ctx=None

    def find_pruned_nodes(self):
        for i in list(self.scopes.keys()):
            self.prune(i)

    def prune(self,start):
        pruned_nodes=[]
        for i in self.scopes[start]['ancestors']:
            if i:
                x=self.right_siblings(i)
                if x:
                    pruned_nodes.extend(x)
        self.scopes[start]['ignore_nodes']=pruned_nodes

    def siblings(self,current):
        return siblings(current)

    def left_siblings(self,current):
        return self.siblings(current)[0]

    def right_siblings(self,current):
        return self.siblings(current)[1]

    def scopeleft_siblings(self,current):
        if type(current)==CParser.FunctionDefinitionContext:
            return None
        else:
            parent=current.parentCtx
            family=list(parent.getChildren())
            younger=None
            if len(family)>0:
                for i in range(0,len(family)):
                    if current==family[i]:
                        break
                younger=family[0:i]
                return younger
            else:
                return self.left_siblings(parent)

    def scoperight_siblings(self,current):
        if type(current)==CParser.FunctionDefinitionContext:
            return None
        else:
            parent=current.parentCtx
            family=list(parent.getChildren())
            older=None
            if len(family)>0:
                for i in range(0,len(family)):
                    if current==family[i]:
                        break
                older=family[i+1:]
                return older
            else:
                return self.scoperight_siblings(parent)

    def get_last_child(self,node):
        n=node
        while type(n)!=tree.Tree.TerminalNodeImpl:
            n=list(n.getChildren())[-1]
        return n

    def get_scope_limits(self,node):
        children=list(node.getChildren())
        valid_scope=[node]
        invalid_scope=[]
        corner=False
        if node==CParser.FunctionDefinitionContext:
            pass
        if node==CParser.CompoundStatementContext:
            pass
        if node==CParser.SelectionStatementContext:
            valid_scope=children[:5] # StatementContext
            if len(children)>5:
                invalid_scope=children[5:]
            else:
                corner=True
        if node==CParser.IterationStatementContext:
            valid_scope=children[:5] # StatementContext
            if len(children)>5:
                invalid_scope=children[5:]
            else:
                corner=True
        return ((valid_scope,invalid_scope),(node,self.get_last_child(valid_scope[-1])),corner)

    def is_else(self,node):
        return type(node)==tree.Tree.TerminalNodeImpl and node.getText()=="else"

    def getParentScopes(self,start):
        # add the current node to the previous hierarchy's descendant list
        self.cur_scopes[-1].append(start)
        # create a new list to accumulate descendants
        self.cur_scopes.append([])
        pscopes=[]
        p=[start]
        siblings=self.siblings(start)
        self.scopes[start]=dict()
        self.scopes[start]['children']=list(start.getChildren())
        self.scopes[start]['parent']=start.parentCtx
        self.scopes[start]['func_ctx']=self.current_fn_ctx
        self.scopes[start]['scope_limits']=self.get_scope_limits(start)
        self.scopes[start]['siblings']=siblings
        done=(type(start)==CParser.FunctionDefinitionContext)
        CASE=0
        while not done:
            dprint(f"{CASE} : {type(p[-1])} [start? {p[-1]==start}]")
            CASE+=1
            if p[-1] == start:
                p.append(p[-1].parentCtx)
                continue
            if type(p[-1]) in self.valid_parent_scopes:
                capture=True
                x=min(5,len(p))
                dprint(f"Valid scope parent: {type(p[-1])}")
                dprint(f" ===> Last {x} parents! ")
                for i in range(0,x):
                    dprint(f" [{i}] : {type(p[i-x])} ")
                    # [ {get_string2(p[x-i-1])} ]")
                if type(p[-1])==CParser.SelectionStatementContext:
                    lsiblings=self.left_siblings(p[-2])
                    for i in range(0,len(lsiblings)):
                        dprint(f" sibling [{i}] : {type(lsiblings[i])} [ {get_string2(lsiblings[i])} ]")
                        pass
                    if self.is_else(lsiblings[-1]):
                        dprint(f"In an else condition, don't capture {type(p[-1])}")
                        capture=False
                if capture:
                    pscopes.append(p[-1])
                    if p[-1] in self.resolved:
                        dprint(f"RESOLVED : {type(start)} => {type(p[-1])} ")
                        last=p.pop()
                        if type(last) == CParser.FunctionDefinitionContext:
                            done=True
                            break
                        else:
                            x=self.scopes.get(last,None)
                            if x:
                                dprint(f" converged parent => {type(last)}")
                                pscopes.extend(x['pscopes'])
                                p.extend(x['ancestors'])
                                done=True
                                break
            p.append(p[-1].parentCtx)

        self.scopes[start]['pscopes']=pscopes
        self.scopes[start]['ancestors']=p
        self.resolved.append(start)

    def exitExternalDeclaration(self,ctx:CParser.ExternalDeclarationContext):
        pass

    def enterExternalDeclaration(self,ctx:CParser.ExternalDeclarationContext):
        pass

    def exitCompoundStatement(self,ctx:CParser.CompoundStatementContext):
        x=self.cur_scopes.pop()
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        pass

    def enterCompoundStatement(self,ctx:CParser.CompoundStatementContext):
        x=self.scopes.get(ctx,None)
        if x:
            print("[DuplicateNodeError] {get_string(ctx)}")
        else:
            self.getParentScopes(ctx)
        pass

    def exitSelectionStatement(self, ctx:CParser.SelectionStatementContext):
        x=self.cur_scopes.pop()
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        pass

    def enterSelectionStatement(self, ctx:CParser.SelectionStatementContext):
        x=self.scopes.get(ctx,None)
        if x:
            print("[DuplicateNodeError] {get_string(ctx)}")
        else:
            self.getParentScopes(ctx)
        pass

    def exitIterationStatement(self, ctx:CParser.IterationStatementContext):
        x=self.cur_scopes.pop()
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        pass

    def enterIterationStatement(self, ctx:CParser.IterationStatementContext):
        x=self.scopes.get(ctx,None)
        if x:
            print("[DuplicateNodeError] {get_string(ctx)}")
        else:
            self.getParentScopes(ctx)
        pass

    def enterFunctionDefinition(self,ctx:CParser.FunctionDefinitionContext):
        self.current_fn_ctx=ctx
        x=self.scopes.get(ctx,None)
        if x:
            print("[DuplicateNodeError] {get_string(ctx)}")
        else:
            self.getParentScopes(ctx)
        pass

    def exitFunctionDefinition(self,ctx:CParser.FunctionDefinitionContext):
        self.find_pruned_nodes()
        self.current_fn_ctx=None
        x=self.cur_scopes.pop()
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        pass


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
    if debug[0]:
        print(instr,flush=flush)
    else:
        global gbl_debug_msg
        if gbl_debug_msg[3]:
            if gbl_debug_msg[1]%50 == 0:
                write_log()
                gbl_debug_msg[0]=""
            else:
                gbl_debug_msg[0]+=instr+"\n"
            gbl_debug_msg[1]+=1

def write_log():
    if gbl_debug_msg[3]:
        gbl_debug_msg[2].write(gbl_debug_msg[0])

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

#get all types of ctx
#use to find functions or conditional statements
def find_ctx_list(tree,ctx,screen=None):
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
        if str(t) in ctx:
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

# unused
def find_scope_descendant(ancestor,descend_lineage):
    indx=descend_lineage.index(ancestor)
    return descend_lineage[indx-1]


def get_function_info(functions,fscope):
    scope_vars=dict()
    variable_lut=dict()
    for ctx in functions:
        fname=ctx
        fargs=get_func_args_nodes(ctx)
        scope_dict=dict()
        scope_vars[fname]=dict()
        compound_scope=list()
        for k,x in fscope.items():
            if x['func_ctx']==ctx:
                scope_dict[k]=x
                if type(k)==CParser.IterationStatementContext or type(k)==CParser.SelectionStatementContext:
                    c=list(k.getChildren())
                    if type(c[4].getChild(0))!=CParser.CompoundStatementContext:
                        dprint(f"iteration/selection scope corner case {len(compound_scope)} : {get_string2(k)}")
                        compound_scope.append((k,True))
                if type(k)==CParser.CompoundStatementContext:
                    dprint(f"compound scope {len(compound_scope)} : {get_string2(k)}")
                    compound_scope.append((k,False))
        dprint(f"len(compound_scope) : {len(compound_scope)}")
        for p,add_p_to_scope_stack in list(compound_scope):
            pscope=dict()
            import copy
            scope_stack=copy.copy(scope_dict[p]['pscopes'])
            if add_p_to_scope_stack:
                scope_stack=[p]+scope_stack
            parent_scope=scope_dict[p]['parent']
            siblings=scope_dict[p]['siblings'] #[0] are younger, [1] older
            ignore_sibs=copy.copy(scope_dict[p]['ignore_nodes'])
            variables=[]
            if fargs and len(fargs)>0:
                variables.extend(list(fargs))
            lut=[ (v[1],v[0]) for v in variables ]
            var_lut=dict(lut)
            values=[]
            cur=None
            scope_end=p
            if add_p_to_scope_stack:
                while scope_end.parentCtx!=scope_stack[1]:
                    scope_end=scope_end.parentCtx
            dprint(f"SCOPE STACK : {add_p_to_scope_stack} ")
            dprint(f"START SCOPE : [ {type(p)} => {get_string2(p)} ] ")
            dprint(f"END SCOPE   : [ {type(scope_end)} => {get_string2(scope_end)} ] ")

            for i in range(0,len(scope_stack)):
                dprint(f" scope [{i}] : {type(scope_stack[i])}")
            i=0
            while(len(scope_stack)>0):
                i+=1
                cur=scope_stack.pop()
                cur_info=scope_dict.get(cur,None)
                nxt=scope_stack[-1] if len(scope_stack)>0 else None
                if not cur_info:
                    print(f" ERROR : {type(cur)} does not exist in scope_dict!")
                    i+=1
                    continue
                curscope_limits=cur_info['scope_limits'][0]
                desc_scopes=cur_info['descendants']
                #children=[x for x in scope_dict[cur]['children'] if x!=scope_stack[-1] ]
                # [0][0] : list of valid subscopes
                # [0][1] : list of invalid subscopes
                # [1][0] : start node
                # [1][1] : last node in valid subscope
                # start evaluation at current node and stop at next scope
                # for each scope, we need to ignore :
                #    1) current scope's invalid subscopes
                #           => curscope_limits[1]
                #    2) descendant scopes
                #           => descendant_scopes
                ignore_me=desc_scopes
                #if curscope_limits[1]:
                #    ignore_me.extend(curscope_limits[1])


                #if nxt:
                #    nxt_subchildren=scope_dict[nxt]['scope_limits'][0][1]
                #    ignore_me.extend([nxt]+nxt_subchildren)
                # get_decls(ctx,var_lut:dict,ignore_me:list):
                #    ignore_me : list of nodes to stop after finding
                #    var_lut   : look-up table for variables containing type and variable info
                #    ctx       : node to start looking at
                if len(ignore_me)>0:
                    dprint(f"for scope {type(cur)}, ignoring:")
                    for i in range(0,len(ignore_me)):
                        dprint(f" {i} : {type(ignore_me[i])}")

                decls,values,variable_lut[cur],vals_wnodes=get_decls(cur,var_lut,ignore_me)
                pscope[cur]={'variables':decls,'values':values,'symbol2type_lut':variable_lut[cur],'vals_w_nodes':vals_wnodes}
                var_lut=copy.copy(variable_lut[cur])

                dprint(f"var_lut: {var_lut.keys()}")
                # get local variable declarations in scope
                variables=pscope[cur]['variables']
                values=pscope[cur]['values']
                vals_w_nodes=pscope[cur]['vals_w_nodes']
            dprint(f"LAST SCOPE OF {type(p)} : {type(cur)}")
            scope_vars[fname][p]={'variables':variables,\
                                  'values':values,\
                                  'symbol2type_lut':var_lut,\
                                  'parent':parent_scope,\
                                  'scope_end':scope_end,
                                  'vals_w_nodes':vals_w_nodes\
                                  }
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

def is_literal(val):
    # if is a digit
    import re
    if re.match(r"\d+",val):
        return True
    return False

def get_fix_loc_subfns(scope):
    uniques=[]
    fn_body=[]
    rewrites=[]
    for i,f_info in enumerate(scope.items()):
        fn,fs=f_info
        type_lut=dict()
        def_vars = get_all_vars(fn, False)
        strip_array_decs(def_vars)
        scp_fn=f"fix_ingred_{i}()"
        fn_decl=f"void {scp_fn}"+"{\n"
        scopefn_decls=""
        scopefn_defs=""
        for j, s_info in enumerate(fs.items()):
            sn,s=s_info
            uniq_init=[]
            scope_uniq=[]
            parent=s['parent'] if s['parent'] else sn
            var_s=s['variables']
            sym_lut=s['symbol2type_lut']
            #val_s=s['values']
            val_s=s['vals_w_nodes']
            end=s['scope_end']
            for x in val_s:
                try:
                    type_info,var,varinfo,value_node=x
                    if value_node:
                        term=list(find_multictx(value_node,[tree.Tree.TerminalNodeImpl]))
                        value=get_string2(value_node)
                        value_subterms=[get_string2(v) for v in term]
                        dprint(f"Subterms : {' '.join(value_subterms)}")
                        # if any RHS uses a variable, obtain its type from var_s (variable look-up table)
                        # and add it to the unique scope list of required variables
                        for v in value_subterms:
                            if not is_literal(v):
                                vtype = sym_lut.get(v,None)
                                if vtype:
                                    vtyp=vtype
                                    if type(vtype)!=str:
                                        vtyp=get_string2(vtype)
                                    info=(vtyp,v,None)
                                    if info in uniq_init:
                                        continue
                                    else:
                                        uniq_init.append(info)
                        # now we're looking at each set of variables and the RHS value
                        import re
                        typ=re.sub(r"\bconst\b",r' ',type_info)
                        x=type_lut.get(typ,None)
                        if not x:
                            type_lut[typ]=[]
                        for def_var in def_vars:
                            info=(typ,def_var,value)
                            if info in uniques:
                                continue
                            else:
                                uniques.append(info)
                                scope_uniq.append(info)
                except Exception as e:
                    print(f"Exception with x={x}")
                    print(e)
                    raise
            # now take the uniq_init list and generate the pre-req variable types
            # i : function id ; j : scope_id 
            decl_vars=[]
            if len(scope_uniq)>0:
                scp_fn=f"fix_ingred_{i}_{j}()"
                scp_fn_decl=f"void {scp_fn};"
                scp_body=""
                for u in uniq_init:
                    utyp,uname,uval=u
                    scp_body+=f"{utyp} {uname};\n"
                    decl_vars.append(uname)
                # and then take the scope_uniq list and generate the initialized values
                for u in scope_uniq:
                    utyp,uname,uval=u
                    if uname not in decl_vars:
                        scp_body+=f"{utyp} {uname}; {uname} = {uval};\n"
                        decl_vars.append(uname)

                scp_fn_def=f"void {scp_fn}"+"{\n"+f"{scp_body}"+"}"
                call_fn=f"{scp_fn};\n"
                fn_decl+=f"{call_fn}"
                scopefn_decls+=f"{scp_fn_decl}\n"
                scopefn_defs+=f"{scp_fn_def}\n"
                loc = get_end_loc(end)
                rewrites.append((call_fn,loc))
        fn_decl+="}\n"
        print("[Fix Ingredient functions]  -- START --")
        prepend=f"{scopefn_decls}\n{scopefn_defs}"
        print(prepend)
        loc= get_start_loc(fn)
        rewrites.append((prepend,loc))
        print("[Fix Ingredient functions]  --  END  --")
    return rewrites



    

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
            end=s['scope_end']
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
                            loc = get_end_loc(end)
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

def str_nodes_cond(t:list):
    x=[]
    for i in range(0,len(t)):
        if t[i][0] and t[i][1]:
            if type(t[i][1])!=str:
                x.append(get_string2(t[i][1]))
            else:
                x.append(t[i][1])
        else:
            x.append(t[i][1])
    return tuple(x)

def str_nodes(t:list):
    for i in range(0,len(t)):
        if t[i] and type(t[i])!=str:
            t[i]=get_string2(t[i])
    return tuple(t)

def get_decl_info(vt,found,lut):
    val_t=list()
    valnodes_t=list()
    str_found=[get_string2(f) for f in found]
    if vt:
        for v in vt:
            type_n,decl_n,value_n=v
            if decl_n in found or decl_n in str_found:
                continue
            declaration=list(decl_n.getChild(0).getChildren())
            decl_info=""
            decl_nodes=[]
            if len(declaration)>1:
                decl_nodes=list(declaration[1:])
                for i in range(1,len(declaration)):
                    decl_info+=get_string2(declaration[i])
                d=get_string2(declaration[0])
                lut[d]=get_string2(type_n)+" *"
                found.append(declaration[0])
                str_found.append(d)
            lut[get_string2(decl_n)]=type_n
            val_t.extend([str_nodes([type_n,declaration[0],decl_info,value_n])])
            valnodes_t.extend([str_nodes_cond([(True,type_n),(True,declaration[0]),(True,decl_info),(False,value_n)])])
            found.append(decl_n)
            str_found.append(get_string2(decl_n))
    return val_t,found,str_found,lut,valnodes_t

def get_decls(ctx,var_lut:dict,ignore_me:list):
    # we don't want to go beyond the current scope
    start=ctx
    #screen_me=[CParser.FunctionDefinitionContext,CParser.IterationStatementContext]

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

    declarations=list()

    val_t=list()
    valnodes_t=list()
    found=list()
    str_found=list()
    vardict=dict()
    vars_t=list()
    typs_t=list()
    for d in check_these_nodes:
        chld=list(d.getChildren())
        ignore_siblings=siblings(d)[1]
        var_t,typ_t=(None,None)
        l_ignore=ignore_me
        if ignore_siblings:
            if not l_ignore:
                l_ignore=list()
            l_ignore.extend(ignore_siblings)
        if type(d)==CParser.ForDeclarationContext:
            dprint(f"FOR : {get_string2(d)}")
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
            vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
                valnodes_t.extend(valnodes)
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
                vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
                    valnodes_t.extend(valnodes)
            if len(chld) == 2:
                # this is a bug you see when you have 'int a;'
                node=chld[0]
                typ=node.getChild(0)
                var=node.getChild(1)
                # type,variable,initial_value
                f= [ (typ,var,None) ]
                var_t=[var]
                typ_t=[typ]
                vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
                    valnodes_t.extend(valnodes)
        if type(d)==CParser.RelationalExpressionContext or type(d)==CParser.EqualityExpressionContext:
            varlkup1=get_string2(chld[0])
            varlkup2=get_string2(chld[2])
            typ1=var_lut.get(varlkup1,vardict.get(varlkup1,None))
            typ2=var_lut.get(varlkup2,vardict.get(varlkup2,typ1))
            if typ1==None and typ2 == None:
                dprint(f"[WARNING] Looks like we've hit an unimplemented case for LHS={varlkup1},RHS={varlkup2}")
                dprint(f"[WARNING] Check this line: {get_string2(d)} ")
                dprint(f"[VERIFY] {var_lut.items()}")
                dprint(f"[VERIFY] {vardict.items()}")
                dprint(f"[WARNING] found: {[get_string2(f) for f in found]} ")
                dprint(f"[WARNING] SKIPPING ")
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
            vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
                valnodes_t.extend(valnodes)

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
            vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
            if vt:
                val_t.extend(vt)
                valnodes_t.extend(valnodes)
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
                vt,found,str_found,var_lut,valnodes=get_decl_info(f,found,var_lut)
                if vt:
                    val_t.extend(vt)
                    valnodes_t.extend(valnodes)
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

    return declarations,val_t,var_lut,valnodes_t

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
    p,t =get_tree_from_file("test_files/service.i")
    g = get_typedefs_from_ctx(t)
    print(get_typedef_from_set(g,set(['unsigned','long'])))
    return g
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

#Input: a context should be the whole parse tree
#Output: all the typedefine contexts that are basic data types that were just renamed
def get_typedefs_from_ctx(ctx):
    sel_stmt = "<class 'CParser.CParser.DeclarationSpecifiersContext'>"
    macs = find_ctx(ctx, sel_stmt)
    t_defs = [x for x in macs if x.getText().startswith("typedef")]
    #might be a good idea to add pointers to all these types
    base_types = set(['int','long','char','float','double','short','signed','unsigned'])
    ret = []
    for t in t_defs:
        brkn = set([t.getChild(x).getText() for x in range(t.getChildCount())][1:-1])
        if brkn.issubset(base_types) and brkn != set():
            ret.append(t)
    return ret

#Input: A set of contexts' that have typedefines with basic data types
#Output:The name of the typedef
def get_typedef_from_set(t_defs, type_set):
    ret = []
    for t in t_defs:
        brkn = [t.getChild(x).getText() for x in range(t.getChildCount())]
        #trim off "typedf" and type-name
        brkn_set = set(brkn[1:-1])
        if type_set == brkn_set:
            ret.append(brkn[-1])
    return ret

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

def parse_func_call_args(ctx):
    a = ctx.getChild(2)
    aes = [a.getChild(x).getText() for x in range(a.getChildCount()) if x % 2 == 0]
    return aes

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

def get_json_data(fname):
    rd = {}
    d1 = {}
    d2 = {}
    with open(fname, 'r') as j:
        data = json.load(j)
        if 'filenames' in data.keys():
            #do the thing here
            fls = data["filenames"]
            flst = [x["name"] for x in fls]
            d1,d2 = parse_pre_process(flst)
        if "macros" in data.keys():
            mcs = data["macros"]
            for i in range(len(mcs)):
                rd[mcs[i]['name']] = mcs[i]['value']

    return (d1,d2,rd)

#Input a file with a list of .c files to search functions for
#Output a dictionary of functions and their arguments
def parse_pre_process(cnts):
    #return dictionary
    ret_d = {}
    ret_d2 = {}
    for c in cnts:
        #read all the files and pull out the functions from each file to return
        p,t = get_tree_from_file(c)
        fns = get_functions(t)
        for f in fns:
            ret_d[get_func_name(f)] = get_func_args(f)
            ret_d2[get_func_name(f)] = f.getChild(0).getText()
    return ret_d,ret_d2

if __name__ == "__main__":
    import atexit
    atexit.register(write_log)
    main()
else:
    import atexit
    atexit.register(write_log)

