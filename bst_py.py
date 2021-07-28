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
            
    def get_max(self, root):
        temp = root
        max_elm = 0
        while (temp.right != None):
            temp = temp.right
        max_elm = temp.data
        print("Maximum element: ",max_elm)
        return max_elm
    
    def get_min(self, root):
        temp = root
        min_elm = 0
        while(temp.left != None):
            temp = temp.left
        min_elm = temp.data
        print("Minimum element: ",min_elm)
        return min_elm
    
if __name__ == "__main__":
    bst = BST()
    root = bst.create_node(20)
    root = bst.add_node(root, 10)
    root = bst.add_node(root, 30)
    root = bst.add_node(root, 40)
    bst.postorder(root)
    max_elm = bst.get_max(root)
    min_elm = bst.get_min(root)
