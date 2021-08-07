'''
Name: graph_dfs_py.py
Aim: To implement Depth-First-Search traversal of graph
Date: 7.August 2021
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
        print("INFO: Added node and edges to the graph")
        self.graph.update({node:edge_list})
        
    def count_nodes(self):
        print("INFO: Current no of nodes in the graph are:",len(self.graph.keys()))
    
    def depth_first_search(self):
        dfs = []
        print("NOTE: Starting element of the graph is:",list(self.graph.keys())[0])
        super().push_to_stack(list(self.graph.keys())[0]) # push the first node to stack; starting node
        while(super().current_size() > 0):
            elm = super().pop_from_stack()
            dfs.append(elm)
            for item in list(self.graph[elm]):
                super().push_to_stack(item)
        return dfs
    
    def breadth_first_search(self):
        bfs = []
        print("NOTE: Starting element of the graph is:",list(self.graph.keys())[0])
        Queue().enque(list(self.graph.keys())[0])
        return bfs
    
grph = Graph()
grph.add_nodes('a', ['b', 'c'])
grph.add_nodes('b', ['d'])
grph.add_nodes('c', ['e'])
grph.add_nodes('d', ['f'])
grph.add_nodes('e', [])
grph.add_nodes('f', [])
grph.count_nodes()
dfs = grph.depth_first_search()
print("Depth-First-Search traversal of the graph is:",dfs)

