'''
Name: graph_bfs_py.py
Aim: To implement Breadth-First-Search graph traversal
Date: 7.August 2021
'''

class Queue():
    def __init__(self):
        print("INFO: Queue created")
        self.queue_list = []  # init an empty list for queue implementation
        
    def enque(self, element):
        self.queue_list.append(element)
        print("INFO: Adding",element,"to the queue")
        
    def deque(self):
        if (len(self.queue_list) > 0): # if queue is empty, print error message and return -1, else element
            el = self.queue_list.pop(0)
        else:
            el = -1
        print("INFO: Removing",el,"from the queue")
        return el
    
    def queue_size(self):
        print("INFO: Size of the queue currently is:",len(self.queue_list))
        return len(self.queue_list)
    
class Graph(Queue):  # inherit Queue class in Graph class
    def __init__(self):
        super().__init__()
        self.graph = {}  # init a empty dict for the graph
        print("INFO: Graph created")
        
    def add_nodes(self, node, edge_list):
        print("INFO: Added node and edges to the graph")
        self.graph.update({node:edge_list})
        
    def count_nodes(self):
        print("INFO: Current no of nodes in the graph are:",len(self.graph.keys()))
    
    def breadth_first_search(self):
        bfs = []
        print("NOTE: Starting element of the graph is:",list(self.graph.keys())[0])
        super().enque(list(self.graph.keys())[0])
        while(self.queue_size() > 0):
            el = super().deque()
            bfs.append(el)
            for item in list(self.graph[el]):
                super().enque(item)
        return bfs
    
grph = Graph()
grph.add_nodes('a', ['b', 'c'])
grph.add_nodes('b', ['d'])
grph.add_nodes('c', ['e'])
grph.add_nodes('d', ['f'])
grph.add_nodes('e', [])
grph.add_nodes('f', [])
grph.count_nodes()
bfs = grph.breadth_first_search()
print("Breadth First Traversal for graph is: ",bfs)
