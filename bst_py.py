"""
Name: bst_py.py
Aim: To implement Binary Search Tree in Python
Date: 28.July 2021
Functions implemented:  creating nodes, adding nodes,
                        preorder, inorder, postorder,
"""
class Node():
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
class BST():
    def create_node(self, data):
        node = Node(data)
        return node
    
    def add_node(self, root, data):
        if (root == None):
            return self.create_node(data)
        elif (data > root.data):
            root.right = self.add_node(root.right, data)
        else:
            root.left = self.add_node(root.left, data)
        return root
    
    def inorder(self, root):
        if (root != None):
            self.inorder(root.left)
            print("Node: ",root.data)
            self.inorder(root.right)
        
    def preorder(self, root):
        if (root != None):
            print("Node: ",root.data)
            self.preorder(root.left)
            self.preorder(root.right)
            
    def postorder(self, root):
        if (root != None):
            self.postorder(root.left)
            self.postorder(root.right)
            print("Node: ",root.data)
            
if __name__ == "__main__":
    bst = BST()
    root = bst.create_node(20)
    root = bst.add_node(root, 10)
    root = bst.add_node(root, 30)
    #bst.postorder(root)
