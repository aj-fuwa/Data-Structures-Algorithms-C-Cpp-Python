/*
Name: linked_list_cpp.cpp
Aim: To implement Linked list in C++
Date: 28.July 2021
*/
#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* link;
};

typedef Node* node;

node add_at_end(node head, int data){
	node temp = head;
	node new_node = NULL;
	while(temp->link != NULL){
		temp = temp->link;
	}
	new_node = new Node();
	new_node->data = data;
	new_node->link = NULL;
	temp->link = new_node;
	return head;
}

void print_list(node head){
	node temp = head;
	while(temp != NULL){
		cout<<"Node: "<<temp->data<<endl;
		temp = temp->link;
	}
}

int main(){
	node head = NULL;
	node second = NULL;
	node third = NULL;
	
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->link = second;

	second->data = 2;
	second->link = third;

	third->data = 3;
	third->link = NULL;
	
	head = add_at_end(head, 40);
	head = add_at_end(head, 50);
	print_list(head);
	return 0;

}
