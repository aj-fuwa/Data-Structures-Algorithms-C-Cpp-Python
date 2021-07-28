/*
Name: linked_list_c.c
Aim: To implement a one-way linked list in C
Date: 23.July 2021
Functions implemented:  add node at position; add at end; add at beginning;
                        delete node at position; delete the last node; delete the first node;
                        length of the linked list (iterative and recursive); print the list; create a new list;
                        TODO: delete a value; reverse the list; sort the list
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

typedef struct Node* node;

node add_at_end(node head, int data){
	node temp = head;
	node new_node = NULL;
	while(temp->link != NULL){
		temp = temp->link;
	}
	new_node = (node)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = NULL;
	temp->link = new_node;
	return head;
}

node add_at_begin(node head, int data){
	node new_node = (node)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = head;
	head = new_node;
	return head;
}

node create_list(int data){
	node head = (node)malloc(sizeof(struct Node));
	head->data = data;
	head->link = NULL;
	return head;
}

node add_at_pos(node head, int data, int pos){
	node temp = head;
	node new_node = (node)malloc(sizeof(struct Node));
	int count = count_nodes(head);
	int index = 1;
	if(count < pos){
		printf("ERROR: Position is greater than the count of nodes\n");
		return head;
	}
	if(pos == 1 && count > 1){
		head = add_at_begin(head, data);
		return head;
	}
	if(pos == 1 && count < 1){
		head = create_list(data);
		return head;
	}
	new_node->data = data;
	while(temp != NULL){
		if(index == pos - 1){
			new_node->link = temp->link;
			temp->link = new_node;
			return head;
		}	
	}
}

node del_at_begin(node head){
	node del_node = NULL;
	del_node = head;
	head = head->link;
	free(del_node);
	return head;
}	

node del_at_pos(node head, int pos){
	int index = 0;
	int count = count_nodes(head);
	node del_node = NULL;
	node temp = head;
	if(count < pos){
		printf("ERROR: Position is greater than the number of nodes in the list\n");
		return head;
	}
	if(pos == 1 && count > 1){
		head = del_at_begin(head);
		return head;
	}
	while(temp != NULL){
		if(index == pos - 1){
			del_node = temp->link;
			temp->link = del_node->link;
			free(del_node);
			return head;
		}
	}
}

node del_at_end(node head){
	node temp = head;
	node del_node = NULL;
	while(temp->link->link != NULL){
		temp = temp->link;
	}
	del_node = temp->link;
	temp->link = NULL;
	free(del_node);
	return head;
}

void print_list(node head){
	node temp = head;
	while(temp != NULL){
		printf("Node: %d \n",temp->data);
		temp = temp->link;
	}
}

int count_nodes(node head){
	node temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->link;
	}
	return count;
}

int count_nodes_rec(node head){
	if (head == NULL){
		return 0;
	}
	else{
		return 1 + count_nodes_rec(head->link);	
	}
}

int main(void){
	int val = 0;
	node head = create_list(10);
	
	head = add_at_end(head, 20);
	head = add_at_end(head, 30);
	head = add_at_begin(head, 40);
	head = add_at_end(head, 50);
	
	//head = del_at_begin(head);
	head = del_at_pos(head, 2);
	
	print_list(head);
	val = count_nodes(head);
	printf("No of nodes in the list: %d\n", val);
	
	return 0;
}
