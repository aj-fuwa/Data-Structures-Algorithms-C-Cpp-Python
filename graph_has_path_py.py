'''
Name: graph_has_path_py.py
Aim: To check if a path exists between two given nodes
Date: 8.August 2021
'''
class Stack():
    def __init__(self):
        print("INFO: Stack created")
        self.stack = []  # init an empty list for the stack implementation
        
    def push_to_stack(self, element):
        print("INFO: Pushed",element,"to the stack")
        self.stack.append(element)
    
    def pop_from_stack(self):
        if (len(self.stack) > 0):   # if stack is empty, print error message and return -1, else element
            element = self.stack.pop(-1)
            print("INFO: Popped",element,"from the stack")
        else:
            element = -1
            print("ERROR: Stack is empty. Pop function failed")
        return element
        
    def peek_stack(self):
        if (len(self.stack) > 0):
            print("INFO: Top of the stack currently is:",self.stack[-1])
        else:
            print("ERROR: Stack is empty. Peek function failed")
        
    def current_size(self):
        print("INFO: Current size of the stack is: ",len(self.stack))
        return len(self.stack)
      
class Graph(Stack):  # inherit Stack and Queue classes in Graph class
    def __init__(self):
        super().__init__()
        self.graph = {}  # init a empty dict for the graph
        print("INFO: Graph created")
        
    def add_nodes(self, node, edge_list):
        #print("INFO: Added node and edges to the graph")
        self.graph.update({node:edge_list})
        
    def count_nodes(self):
        print("INFO: No of nodes in the graph are:",len(self.graph.keys()))
    
    def has_path(self, src_node, dest_node):  # return True if path found, else False
        src_node = src_node.lower()
        dest_node = dest_node.lower()
        print("INFO: Checking path between ",src_node,"and",dest_node)
        super().push_to_stack(src_node)
        match = False
        while(super().current_size() > 0 or match == False):
            elm = super().pop_from_stack()
            if (elm == dest_node):
                match = True
            if (len(list(self.graph[elm])) == 0):
                break
            else:
                for item in list(self.graph[elm]):
                    super().push_to_stack(item)
        return match
        
    
grph = Graph()
grph.add_nodes('a', ['b', 'c'])
grph.add_nodes('b', ['d'])
grph.add_nodes('c', ['e'])
grph.add_nodes('d', ['f'])
grph.add_nodes('e', [])
grph.add_nodes('f', [])
grph.count_nodes()
src = 'e'
dest = 'f'
if (grph.has_path(src, dest)):
    print("OUT: Path is present between",src,"and",dest)
else:
    print("OUT: No path between",src,"and",dest)


