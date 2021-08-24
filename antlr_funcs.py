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

def get_type_var_info(ctx):
    chld=list(ctx.getChildren())
    nodes=[]
    if len(chld)<=1:
        return None,None,None
    elif len(chld)==3:
        typ=get_string2(chld[0])
        node=chld[1]
        dec=list(find_multictx(node,[CParser.DeclaratorContext],None,None))
        nodes=[(typ,d) for d in dec]
    elif len(chld)==2:
        checkme=chld[0];
        c=list(checkme.getChildren())
        typ,node=(None,None)
        if len(c)==2:
           typ=get_string2(c[0])
           node=c[1]
        elif len(c)==3:
           typ=" ".join([get_string2(x) for x in c[0:2]])
           node=c[2]
        nodes=[(typ,node)]
    sym_dict=dict()
    up_nodes=list()
    for t,d in nodes:
        c=list(d.getChild(0).getChildren())
        if len(c)>1:
            decl_info=""
            decl_nodes=list(c[1:])
            for i in range(1,len(c)):
                decl_info+=" "+get_string2(c[i])
            d_=get_string2(c[0])
            typ=t+" *"
            sym_dict[d_]=typ
            up_nodes.extend([(typ,c[0],decl_info)])
        up_nodes.extend([(t,d,None)])
        
    return nodes, sym_dict, up_nodes

class ScopeListener(CListener):
    cur_scopes=[ [], ]
    cur_declarations=[ [], ]
    cur_symbol_lut=dict()
    cur_assignments=[ [], ]
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
    current_scope=None

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
        if self.current_scope:
            self.cur_symbol_lut[start]=copy.copy(self.cur_symbol_lut[self.current_scope])
        else:
            self.cur_symbol_lut[start]=dict()
            #for i,c in enumerate(list(start.getChildren())):
            #    print(f" {i} : {type(c)}")
            #    if i==1:
            #        print(f" {i}[0] : {get_string2(c.getChild(0).getChild(0))}")
            #        print(f" {i}[1] : {get_string2(c.getChild(0).getChild(1))}")
            #        print(f" {i}[2] : {get_string2(c.getChild(0).getChild(2))}")
            #        print(f" {i}[2] : type : {type(c.getChild(0).getChild(2))}")

                    
        self.current_scope=start
        self.cur_scopes[-1].append(start)
        # create a new list to accumulate descendants
        self.cur_scopes.append([])
        self.cur_declarations.append([])
        self.cur_assignments.append([])
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
        self.current_scope=self.cur_scopes[-1][-1]
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        x=self.cur_symbol_lut[ctx]
        self.scopes[ctx]['sym_lut']=copy.copy(x)
        x=self.cur_declarations.pop()
        self.scopes[ctx]['decls']=copy.copy(x)
        x=self.cur_assignments.pop()
        self.scopes[ctx]['assigns']=copy.copy(x)
        s=[(n[0],n[1],n[2],get_string2(n[3])) for n in x]
        dprint(f"Assigns = {s}")
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
        self.current_scope=self.cur_scopes[-1][-1]
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        x=self.cur_symbol_lut[ctx]
        self.scopes[ctx]['sym_lut']=copy.copy(x)
        x=self.cur_declarations.pop()
        self.scopes[ctx]['decls']=copy.copy(x)
        x=self.cur_assignments.pop()
        self.scopes[ctx]['assigns']=copy.copy(x)
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
        self.current_scope=self.cur_scopes[-1][-1]
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        x=self.cur_symbol_lut[ctx]
        self.scopes[ctx]['sym_lut']=copy.copy(x)
        x=self.cur_declarations.pop()
        self.scopes[ctx]['decls']=copy.copy(x)
        x=self.cur_assignments.pop()
        self.scopes[ctx]['assigns']=copy.copy(x)
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
        self.current_scope=None
        dprint(f"Descendants of {type(ctx)} : {get_string2(ctx)}")
        for i in range(0,len(x)):
            dprint(f" {i} : {type(x[i])}   [ {get_string2(x[i])} ]")
        self.scopes[ctx]['descendants']=copy.copy(x)
        x=self.cur_symbol_lut[ctx]
        self.scopes[ctx]['sym_lut']=copy.copy(x)
        x=self.cur_declarations.pop()
        self.scopes[ctx]['decls']=copy.copy(x)
        x=self.cur_assignments.pop()
        self.scopes[ctx]['assigns']=copy.copy(x)
        pass

    def exitAssignmentExpression(self, ctx:CParser.AssignmentExpressionContext):
        pass
    def enterAssignmentExpression(self, ctx:CParser.AssignmentExpressionContext):
        chld=list(ctx.getChildren())
        if len(chld)==3 and "=" in get_string2(chld[1]):
            #nodes=get_string2(ctx)
            ovar=get_string2(chld[0])
            var_ext=ovar.split('[',1) if '[' in ovar else [ovar,""]
            var=var_ext[0]
            ext=var_ext[1]
            if ext!="":
                ext="["+ext
            nodes=chld[2]
            dprint(f"var: {var} ({ovar}) = {get_string2(nodes)}")
            typ=self.cur_symbol_lut[self.current_scope].get(var,"UNDEF")
            dprint(f"var: {typ} {var} ({ovar}) = {get_string2(nodes)}")
            if ovar!=var:
                typ=typ.rsplit(' *',1)[0]
            self.cur_assignments[-1].extend([(typ,var,ext,nodes)])
        else:
            pass
        pass

    #def exitInitializer(self, ctx:CParser.InitializerContext):
    #    pass
    #def enterInitializer(self, ctx:CParser.InitializerContext):
    #    if type(ctx.getChild(0))==CParser.AssignmentExpressionContext:
    #        nodes=get_string2(ctx)
    #        print(f"Initializer: {nodes}")
    #        self.cur_assignments[-1].extend([nodes])
    #    pass

    #rules_with_declarations=[CParser.ForDeclarationContext,CParser.DeclarationContext]


    def exitDeclaration(self, ctx:CParser.DeclarationContext):
        pass
    def enterDeclaration(self, ctx:CParser.DeclarationContext):
        if self.current_scope==None:
            pass
        else:
            chld=list(ctx.getChildren())
            nodes=[]
            if len(chld)<=1:
                return
            elif len(chld)==3:
                typ=get_string2(chld[0])
                node=chld[1]
                dec=list(find_multictx(node,[CParser.DeclaratorContext],None,None))
                nodes=[(typ,d) for d in dec]
            elif len(chld)==2:
                checkme=chld[0];
                c=list(checkme.getChildren())
                typ,node=(None,None)
                if len(c)==2:
                   typ=get_string2(c[0])
                   node=c[1]
                elif len(c)==3:
                   typ=" ".join([get_string2(x) for x in c[0:2]])
                   node=c[2]
                nodes=[(typ,node)]

            sym_dict=dict()
            up_nodes=list()
            for t,d in nodes:
                c=list(d.getChild(0).getChildren())
                if len(c)>1:
                    decl_info=""
                    decl_nodes=list(c[1:])
                    for i in range(1,len(c)):
                        decl_info+=" "+get_string2(c[i])
                    d_=get_string2(c[0])
                    typ=t+" *"
                    sym_dict[d_]=typ
                    up_nodes.extend([(typ,c[0],decl_info)])
                up_nodes.extend([(t,d,None)])
                
            self.cur_declarations[-1].extend(up_nodes)
            for a,b in nodes:
                sym_dict[get_string2(b)]=a
            try:
                self.cur_symbol_lut[self.current_scope].update(sym_dict)
            except Exception as e:
                print(e)
                print(f"=> {type(self.current_scope)}")
                print(f"ctx => {get_string2(ctx)}")
                raise(e)
        pass

    def exitForDeclaration(self, ctx:CParser.ForDeclarationContext):
        pass
    def enterForDeclaration(self, ctx:CParser.ForDeclarationContext):
        chld=list(ctx.getChildren())
        typ=get_string2(chld[0])
        node=chld[1]
        dec=list(find_multictx(node,[CParser.DeclaratorContext],None,None))
        nodes=[(typ,d) for d in dec]
        up_nodes=list()
        sym_dict=dict()
        for t,d in nodes:
            c=list(d.getChild(0).getChildren())
            if len(c)>1:
                decl_info=""
                decl_nodes=list(c[1:])
                for i in range(1,len(c)):
                    decl_info+=" "+get_string2(c[i])
                d_=get_string2(c[0])
                typ=t+" *"
                sym_dict[d_]=typ
                up_nodes.extend([(typ,c[0],decl_info)])
            up_nodes.extend([(t,d,None)])
            
        self.cur_declarations[-1].extend(up_nodes)
        for a,b in nodes:
            sym_dict[get_string2(b)]=a
        self.cur_symbol_lut[self.current_scope].update(sym_dict)
        pass

    def exitParameterDeclaration(self, ctx:CParser.ParameterDeclarationContext):
        pass
    def enterParameterDeclaration(self, ctx:CParser.ParameterDeclarationContext):
        chld=list(ctx.getChildren())
        typ=get_string2(chld[0])
        if len(chld)>1 and typ!=CParser.DeclarationSpecifiers2Context:
            node=chld[1]
            dprint(f"ParameterDeclaration : type = {typ}, var = {get_string2(node)} [type={type(node)}]")
            dec=[node]
            if type(node)!=CParser.DeclaratorContext:
                dec=list(find_multictx(node,[CParser.DeclaratorContext],None,None))
            dprint(f" dec = {[get_string2(d) for d in dec]}")
            nodes=[(typ,d) for d in dec]
            up_nodes=list()
            sym_dict=dict()
            for t,d in nodes:
                dprint(f"{t} : {get_string2(d)}")
                c=list(d.getChild(0).getChildren())
                if len(c)>1:
                    decl_info=""
                    decl_nodes=list(c[1:])
                    for i in range(1,len(c)):
                        decl_info+=" "+get_string2(c[i])
                    d_=get_string2(c[0])
                    typ=t+" *"
                    sym_dict[d_]=typ
                    up_nodes.extend([(typ,c[0],decl_info)])
                up_nodes.extend([(t,d,None)])
            
            self.cur_declarations[-1].extend(up_nodes)
            for a,b in nodes:
                sym_dict[get_string2(b)]=a
            self.cur_symbol_lut[self.current_scope].update(sym_dict)
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

def is_not_inscope(node,older):
    found=False
    node_=node
    while not found:
        if type(node_)==CParser.ExternalDeclarationContext:
            return False
        if node_ in older:
            return True
        node_=node_.parentCtx

def is_descendant(node,ancestor):
    found=False
    node_=node
    while not found:
        if type(node_)==CParser.ExternalDeclarationContext:
            return False
        if node_==ancestor:
            return True
        node_=node_.parentCtx

def get_function_info(functions,fscope,dont_eval:list=None):
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
            dprint(f"=======START=======")
            pscope=dict()
            decl_scopes=[]
            assign_scopes=[]
            var_lut=dict()
            import copy
            scope_stack=copy.copy(scope_dict[p]['pscopes'])
            if add_p_to_scope_stack:
                scope_stack=[p]+scope_stack
            else:
                decl_scopes.extend(scope_dict[p]['decls'])
                assign_scopes.extend([n for n in scope_dict[p]['assigns'] if not(any([x in n[3].getText() for x in dont_eval]))])
                var_lut.update(scope_dict[p]['sym_lut'])
            parent_scope=scope_dict[p]['parent']
            siblings=scope_dict[p]['siblings'] #[0] are younger, [1] older
            ignore_sibs=copy.copy(scope_dict[p]['ignore_nodes'])

            cur=None
            scope_end=p
            if add_p_to_scope_stack:
                while scope_end.parentCtx!=scope_stack[1]:
                    scope_end=scope_end.parentCtx
            dprint(f"SCOPE STACK : {add_p_to_scope_stack} ")
            dprint(f"START SCOPE : [ {type(p)} => {get_string2(p)} ] ")
            dprint(f"END SCOPE   : [ {type(scope_end)} => {get_string2(scope_end)} ] ")
            dprint(f"p_decls = {[(get_string2(n[0]),get_string2(n[1]),get_string2(n[2])) for n in scope_dict[p]['decls']]}")

            for i in range(0,len(scope_stack)):
                dprint(f" scope [{i}] : {type(scope_stack[i])}")
            while(len(scope_stack)>0):
                cur=scope_stack.pop()
                cur_info=scope_dict.get(cur,None)
                if not cur_info:
                    print(f" ERROR : {type(cur)} does not exist in scope_dict!")
                    continue

                nxt=scope_stack[-1] if len(scope_stack)>0 else None
                nxt_ignore=ignore_sibs
                nxt_info=None
                if nxt:
                    nxt_info=scope_dict.get(nxt,None)
                    nxt_ignore=nxt_info['ignore_nodes']
                curscope_limits=cur_info['scope_limits'][0]
                desc_scopes=cur_info['descendants']
                var_lut.update(cur_info['sym_lut'])
                local_decls=[n for n in cur_info['decls'] if not is_not_inscope(n[1],nxt_ignore)]
                local_assigns=[n for n in cur_info['assigns'] if not is_not_inscope(n[3],nxt_ignore) and not(any([x in n[3].getText() for x in dont_eval]))]
                decl_scopes.extend(local_decls)
                assign_scopes.extend(local_assigns)
                dprint(f"decls = {[(get_string2(n[0]),get_string2(n[1]),get_string2(n[2])) for n in decl_scopes]}")
                dprint(f"assigns = {[(get_string2(n[0]),get_string2(n[1]),get_string2(n[2]),get_string2(n[3])) for n in assign_scopes]}")
            # end of while
            dprint(f"===> context {get_string2(p)}")
            s=[get_string2(n) for n in ignore_sibs]
            dprint(f"ignore sibs: {s}")
            for j,c in enumerate(decl_scopes):
                dprint(f"{j} : type: {c[0]}, var: {get_string2(c[1])}")
            for j,c in enumerate(assign_scopes):
                dprint(f"{j} : type: {c[0]}, value: {get_string2(c[3])}")
            dprint(f"=======END=======")

            scope_vars[fname][p]=\
                                  {'variables':copy.copy(decl_scopes),\
                                  'values':copy.copy(assign_scopes),\
                                  'symbol2type_lut':copy.copy(var_lut),\
                                  'parent':copy.copy(parent_scope),\
                                  'scope_end':copy.copy(scope_end)
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

def can_cast(ltyp,rtyp):
    # determines if rtyp variable can be cast as ltyp
    equivalent_classes=[set(['int','unsigned int','uint32_t','uint_t','cgc_size_t',\
                        'size_t','uint','void *', 'unsigned long', 'long']),\
                        set(['char','uint8_t']),\
                        set(['long'])
                        ]    
    for eq in equivalent_classes:
        if ltyp.rstrip() in eq and rtyp.rstrip() in eq:
            return True
    return False

def get_fix_loc_subfns(scope,dvars):
    uniques=[]
    fn_body=[]
    rewrites=[]
    ## function scope
    #def get_type_var_info(ctx) => return nodes, sym_dict, up_nodes
    for i,f_info in enumerate(scope.items()):
        fn,fs=f_info
        type_lut=dict()
        #def_vars = get_all_vars(fn, False)
        # add here pemma
        fn_name=get_func_name(fn)
        print(f"Processing [{fn_name}] :",flush=True)
        try:
            def_vars=dvars[fn_name]
        except Exception as e:
            print(f"Can't find {fn_name} in dvars {dvars.keys()}")
            raise(e)
        for d in def_vars:
            dprint(f"[{fn_name}] : {type(d)} : {get_string2(d)}")
        #strip_array_decs(def_vars)
        ## for each namespace scope in function scope
        s2_fn_def=""
        s2_body=""
        s2_calls=""
        for j, s_info in enumerate(fs.items()):
            sn,s=s_info
            uniq_init=[]
            parent=s['parent'] if s['parent'] else sn
            var_s=s['variables']
            sym_lut=s['symbol2type_lut']
            val_s=s['values']
            #val_s=s['vals_w_nodes']
            scope_uniq=[]
            end=s['scope_end']

            #s2_decls=""
            s2_fn=f"fix_ingred_{i}"
            ## for each value in the namespace scope
            for def_var in def_vars:
                n,lut,un=get_type_var_info(def_var)
                #for nn in n:
                #    print(f"{nn[0]} : {get_string2(nn[1])}")
                #for nn in un:
                #    print(f"{nn[0]} : {get_string2(nn[1])} {get_string2(nn[2])}")
                # we're just going to assume a singly declared variable
                ltyp=n[0][0]
                lname=get_string2(n[0][1])
                #####
                for k,x in enumerate(val_s):
                    try:
                        type_info,var,varinfo,value_node=x
                        scope_uniq.append([])
                        dprint(f"[i={i}][j={j}][k={k}] | type: {type_info} ; var : {var} ; varinfo : {varinfo} ; value_node : {get_string2(value_node)}")
                        if value_node:
                            term=list(find_multictx(value_node,[tree.Tree.TerminalNodeImpl]))
                            value=get_string2(value_node)
                            value_subterms=[get_string2(v) for v in term]
                            dprint(f"Subterms : {' '.join(value_subterms)}")
                            # if any RHS uses a variable, obtain its type from var_s (variable look-up table)
                            # and add it to the unique scope list of required variables
                            for v in value_subterms:
                                if not is_literal(v):
                                    dprint(f" => is literal (False) {v}")
                                    vtype = sym_lut.get(v,None)
                                    if vtype:
                                        # check to see if there are any array versions
                                        vtyp=vtype
                                        if '*' in vtyp:
                                            for isym in sym_lut.keys():
                                                if f"{v} [" in isym:
                                                    print(f"BEFORE => literal (False) {v} => {vtyp}")
                                                    v=isym
                                                    vtyp=sym_lut[v]
                                                    print(f"AFTER => literal (False) {v} => {vtyp}")
                                                    break
                                        info=(vtyp,v,None)
                                        if type(vtype)!=str:
                                            vtyp=get_string2(vtype)
                                        if info in uniq_init:
                                            dprint("continue!")
                                            continue
                                        else:
                                            uniq_init.append(info)
                                else:
                                    dprint(f" => is literal (True) {v}")
                            # now we're looking at each set of variables and the RHS value
                            import re
                            rtyp=re.sub(r"\bconst\b",r' ',type_info)
                            x=type_lut.get(rtyp,None)
                            if not x:
                                type_lut[rtyp]=[]
                                #####
                            if not can_cast(ltyp,rtyp): 
                                # if we can't cast the RHS to LHS type, then go to next
                                #print(f"CASTING FAIL: ltype: {ltyp}, lvar: {lname}, rtype : {rtyp}, rvalue: {value}")
                                continue
                            #print(f"CASTING PASS: ltype: {ltyp}, lvar: {lname}, rtype : {rtyp}, rvalue: {value}")
                            info=(ltyp,lname,value,rtyp)
                            dprint(f"[i={i}][j={j}][k={k}] | type : {rtyp}; def_var : {def_var}; value : {value}")
                            if info in uniques:
                                dprint(f"^^ not unique")
                                continue
                            else:
                                dprint(f"^^ unique")
                                uniques.append(info)
                                scope_uniq[k].append(info)
                    except Exception as e:
                        print(f"Exception with x={x}")
                        print(e)
                        raise
            # now take the uniq_init list and generate the pre-req variable types
            # i : function id ; j : scope_id 
            decl_vars=[]
            tdecl_vars=[]

            s1_calls=""
            s1_fn_decl=""
            s1_fn_def=""
            if len(scope_uniq)>0:
                s0_calls=""
                s0_fn_decl=""
                s0_fn_def=""
                s1_fn=f"fix_ingred_{i}_{j}"
                for k in range(0,len(scope_uniq)):
                    s0_body_vals=""
                    s0_body_vars=""
                    valid=False
                    udecl_vars=[]
                    # and then take the scope_uniq list and generate the initialized values
                    for u in scope_uniq[k]:
                        utyp,uname,uval,rtyp=u
                        if (utyp,uname) not in udecl_vars and utyp != "UNDEF":
                            s0_body_vars+=f"{utyp} {uname}; {uname} = ({utyp})({uval});\n"
                            udecl_vars.append((utyp,uname))
                            valid=True
                        elif utyp != "UNDEF":
                            s0_body_vars+=f"{uname} = ({utyp})({uval});\n"
                            valid=True
                        else:
                            dprint("not valid - "+ f"{utyp} {uname}; {uname} = (({utyp}){uval});\n")
                    # only need to generate if we've found a unique (type,variable) tuple
                    if valid:
                        for u in uniq_init:
                            utyp,uname,uval=u
                            s0_body_vals+=f"{utyp} {uname};\n"
                            decl_vars.append(uname)
                        s0_body=f"{s0_body_vals}{s0_body_vars}"
                        # scope 0 function
                        s0_fn=f"{s1_fn}_{k}()"
                        ## scope 0 function declaration
                        #s0_fn_decl+=f"void {s0_fn};\n"
                        # scope 0 function definition (with body)
                        s0_fn_def+=f"void {s0_fn}"+"{\n"+f"{s0_body}"+"}\n"
                        # scope 0 function call
                        s0_call_fn=f"{s0_fn};\n"
                        # set of scope 0 function calls
                        s0_calls+=f"{s0_call_fn}"
                    tdecl_vars.extend(udecl_vars)
                s1_body=""
                # scope 1 function call (used in scope 2 function definition)
                s1_call_fn=f"{s1_fn}();\n"
                s1_calls+=f"{s1_call_fn}"
                #s1_fn_decl="\n"+s0_fn_decl+"\n"+f"void {s1_call_fn}"+"\n"
                s1_body=f"{s0_calls}"
                # scope 0 function definition (with body)
                s1_fn_def+=s0_fn_def+f"void {s1_fn}()"+"{\n"+f"{s1_body}"+"}\n"
                dprint("==== Scope 1 ====\n"+f"{s1_fn_def}")
                #s2_decls+=f"{s1_fn_decl}\n"
                s2_body+=f"{s1_fn}();"+"\n"
                #loc = get_end_loc(end)
                #rewrites.append((s1_call_fn,loc))
                s2_fn_def+=s1_fn_def
        s2_call_fn=f"{s2_fn}();\n"
        s2_calls+=f"{s2_call_fn}"
        s2_fn=f"fix_ingred_{i}()"
        s2_fn_def+=f"void {s2_fn}"+"{\n"+f"{s2_body}"+"}\n"
        dprint("==== Scope 2 ====\n"+f"{s2_fn_def}")
        print("[Fix Ingredient functions]  -- START --")
        prepend=f"{s2_fn_def}"
        print(prepend)
        loc= get_start_loc(fn)
        rewrites.append((prepend,loc))
        open_bracket=list(fn.getChildren())[-1].getChild(0)
        line,c = get_start_loc(open_bracket)
        func=f"{s2_fn};"
        rewrites.append((func,(line+1,c)))
        dprint("[Fix Ingredient functions]  --  END  --")
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
    elif type(ctx)==str:
        return ctx
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
    p,t =get_tree_from_file("test_files/form.c")
    ifs = find_ctx(t , "<class 'CParser.CParser.SelectionStatementContext'>")
    return ifs

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
    aes = [a.getChild(x) for x in range(a.getChildCount()) if x % 2 == 0]
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
    disable_eval=[]
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

        if 'disable_eval' in data.keys():
            disable_eval=list(data['disable_eval'])
    return (d1,d2,rd,disable_eval)

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

def get_all_decs(ctx):
    ret = {}
    #for all functions
    fns = get_functions(ctx)
    for f in fns:
        decs = find_ctx(f, "<class 'CParser.CParser.DeclarationContext'>")
        ret[get_func_name(f)] = decs
    return ret

def get_top_dec_parent(ctx):
    dec1 = CParser.SelectionStatementContext
    dec2 = CParser.StatementContext
    pctx = ctx

    while type(pctx) == dec1 or type(pctx) == dec2:
        pctx = pctx.parentCtx
    return pctx

def get_dec_diffs(d1,d2):
    ret = {}
    for key,value in d1.items():
        origs = []
        s_in = set()
        s_all = set()
        #get all the text of the original
        for v in value:
            origs.append(v.getText())
        # go trough all the new values and see if
        # the new values are in the old
        for v in d2[key]:
            s_all.add(v)
            for o in origs:
                if o.startswith(v.getText()[:-1]):
                    s_in.add(v)
        ret[key] = list(s_all - s_in)

    return ret

if __name__ == "__main__":
    import atexit
    atexit.register(write_log)
    main()
else:
    import atexit
    atexit.register(write_log)

