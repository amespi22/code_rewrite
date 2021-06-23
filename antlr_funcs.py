#! /usr/bin/env python
import sys
from antlr4 import *
from CLexer import CLexer
from CParser import CParser
from CListener import CListener
import inspect
import codecs

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
    test_functs()
    args = get_func_args_from_inp("test.c", "simple_func",'file')
    print(args)

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
    q = []
    #get first set of children
    pushq(q, list(tree.getChildren()))
    #go through all children breadth first
    txt = ""
    while q != []:
        e = popq(q)
        txt += f"Text={e.getText()}\nType={type(e)}\n"
        txt += f"Child Count = {e.getChildCount()}\n"
        txt += "-------\n"
        if e.getChildCount() != 0:
            pushq(q,list(e.getChildren()))
    with open(outf, 'w') as outfile:
        outfile.write(txt)
    """
    outfile = open(outf, 'w')
    outfile.write(txt)
    """

#get all types of ctx
#use to find functions or conditional statements
def find_ctx(tree,ctx):
    q = []
    #get first set of children
    pushq(q, list(tree.getChildren()))
    #go through all children breadth first
    txt = ""
    r = []
    while q != []:
        e = popq(q)
        txt += f"Text={e.getText()}\nType={type(e)}\n"
        txt += "-------\n"
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
            return (None,None)
    except:
        return (None,None)


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
    p,t =get_tree_from_file("test.c")
    fns = get_functions(t)
    print("Found the following functions")
    for f in fns:
        print(f.getText())
        print(f"all func vars {get_all_vars(f)}")
    print_ctx_bfs(fns[0], "tmp")
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
                    r_types.append(d.getChild(0).getChild(0).getText())
                #This works for structs
                if d.getChildCount() == 2:
                    r_vars.append(d.getChild(0).getChild(1).getText())
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

if __name__ == "__main__":
    main()

