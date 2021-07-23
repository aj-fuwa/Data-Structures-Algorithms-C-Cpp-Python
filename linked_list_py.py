"""
Name: linked_list_py.py
Aim: To implement a one-way linked list in Python
Date: 23.July 2021
Functions implemented:  adding node at position; add at beginning; add at end of list;
                        deleting a node; delete the last node; delete the first node;
                        create a new list; length of the list; print the list
                        TODO: reverse the list; sort the list; delete node at position
"""
class Node:
    def __init__(self):
        self.data = 0
        self.link = None

class LinkedListPy:       
    def print_list(self, head):
        temp = head
        while(temp != None):
            print("Node: ",temp.data)
            temp = temp.link
            
    def count_nodes(self, head):
        count = 0
        temp = head
        while(temp != None):
            count += 1
            temp = temp.link
        return count
            
    def create_list(self, data):
        head = Node()
        head.data = data
        head.link = None
        return head
    
    def add_at_start(self, head, data):
        new_node = Node()
        new_node.data = data
        new_node.link = head
        head = new_node
        return head
            
    def add_at_end(self, head, data):
        temp = head
        while(temp.link != None):
            temp = temp.link
        new_node = Node()
        new_node.data = data
        new_node.link = None
        temp.link = new_node
        return head
    
    def add_at_pos(self, head, data, pos):
        if (self.count_nodes(head) < pos):
            print("ERROR: Position is invalid.")
            return head
        temp = head
        new_node = Node()
        new_node.data = data
        count = 1
        while(temp != None):
            if(count == pos-1):
                ph = temp
                temp.link = new_node
                new_node.link = ph.link
                return head
            count += 1
            temp = temp.link
        return head
    
    def delete_value(self, head, value):
        temp = head
        nxt = temp.link
        while(temp != None):
            if(nxt.data == value and temp.link != None):
                out_node = temp.link
                temp.link = out_node.link
                del out_node
                return head
            else:
                temp = temp.link
        print("ERROR: Value not found in the linked list")
        return head
    
    def delete_last_node(self, head):
        temp = head
        nxt = temp.link
        while(nxt.link != None):
            temp = temp.link
            nxt = nxt.link
        del nxt
        temp.link = None
        return head
    
    def delete_first_node(self, head):
        temp = head
        nxt = temp.link
        del temp
        head = nxt
        return head
    
    #def delete_at_pos(self, head, pos):
    
    #def reverse_list(self, head):
    
    #def sort_list(self, head):
        
if __name__=='__main__':    
    llp = LinkedListPy()
    head = llp.create_list(10)
    head = llp.add_at_start(head, 7)
    head = llp.add_at_start(head, 4)
    head = llp.add_at_end(head, 110)
    head = llp.delete_value(head, 190)
    print("No of nodes in the Linked List: ",llp.count_nodes(head))    
    llp.print_list(head)
    

