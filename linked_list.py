#! /usr/bin/env python

class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextnode = None
        self.prevnode = None

class ll:
    def __init__(self):
        self.headnode = None
        self.tailnode = None
        self.length = 0

    def push(self, val):
        self.length += 1
        if self.headnode == None:
            nn = Node(val)
            self.headnode = nn
            self.tailnode = nn
        else:
            nn = Node(val)
            tailnode = self.tailnode
            tailnode.nextnode = nn
            nn.prevnode = tailnode
            self.tailnode = nn

    def push_list(self, val):
        for v in val:
            self.push(v)

    def dequeue(self):
        hn = self.headnode
        if hn == None:
            return None
        else:
            self.length -= 1
            self.headnode = hn.nextnode
            if hn.nextnode != None:
                hn.nextnode.prevnode = None
            else:
                self.tailnode = None
            return hn.dataval

    def print(self):
        cn = self.headnode
        if cn == None:
            return
        while cn.nextnode != None:
            print(cn.dataval)
            cn = cn.nextnode
        print(cn.dataval)

def main():
    linked_list = ll()
    linked_list.push(4)
    linked_list.push("5")
    linked_list.push("this34")
    print(linked_list.length)
    print("linked list values")
    linked_list.print()
    node = linked_list.dequeue()
    linked_list.push("this")
    print(f"Removed {node.dataval}")
    print("new linked list")
    linked_list.print()
    node = linked_list.dequeue()
    linked_list.print()
    node = linked_list.dequeue()
    linked_list.print()
    node = linked_list.dequeue()
    linked_list.print()
    print(linked_list.headnode)
    print(linked_list.tailnode)
    print(linked_list.length)

"""
#get all types of ctx
#use to find functions or conditional statements
def find_ctx(tree, ctx):
    q = linked_list.ll()
    #get first set of children
    q.push_list(list(tree.getChildren()))
    #go through all children breadth first
    r = []
    while q.length > 0:
        e = q.dequeue()
        t = type(e)
        if str(t) == ctx:
            r.append(e)
        if e.getChildCount() != 0:
            q.push_list(list(e.getChildren()))
    return r
"""

if __name__ == "__main__":
    main()

