/*
 * Program name: linked_list.c
 *
 * Aim: To implement a single-way linked list in C which contains the following operations-
 * 			adding a node (at the beginning, at the end, at a particular position),
 * 			deleting a node (at the beginning, at the end, at a particular position),
 * 			creating a list for the first time,
 *			displaying a list, 
 *			sorting the nodes (in ascending order and in descending order)
 * 
 * Date: 20.Mai 2020
 */

#include<stdio.h>
#include<stdlib.h>
#include<error.h>

// Define the node
struct Node{
	int data;
	struct Node* link;
};

typedef struct Node* Node;

// used to maintain a global value of the number of the nodes
int count_node;
int* count_node_ptr = &count_node;

// function for displaying the nodes
void display_list(Node start){
	Node tmp=(Node)malloc(sizeof(struct Node));
	tmp = start;
	count_node = 0;
	while(tmp != NULL){
		printf("Data for node %d is: %d\n",count_node+1,tmp->data);
		tmp = tmp->link;
		count_node++;
	}
	printf("Total number of nodes: %d\n",count_node);
}

// function to create the list for the first time
Node create_list(int element){
	printf("Creating the linked list....\n");
	Node start = (Node)malloc(sizeof(struct Node));
	start->data = element;
	start->link = NULL; 
	return start;
}

// function to add a node at the beginning
Node add_at_beg(Node start, int element){
	printf("Adding node at the beginning of the list....\n");
	Node new_node = (Node)malloc(sizeof(struct Node));
	Node tmp = NULL;
	tmp = start;
	new_node->data = element;
	new_node->link = tmp;
	start = new_node;
	return start;
}

// function to add a node at the end of the list
Node add_at_end(Node start, int element){
	printf("Adding node at the end of the list..... \n");
	Node new_node = (Node)malloc(sizeof(struct Node));
	Node tmp = NULL;
	tmp = start;
	new_node->data = element;
	while(tmp->link != NULL){
		tmp = tmp->link;
	}
	tmp->link = new_node;
	new_node->link = NULL;
	return start;
}

// function to add a node at a particular position
Node add_at_pos(Node start, int element, int pos){
	printf("Adding node at position: %d..... \n",pos);
	if(pos == 1){
		start = create_list(element);
		return start;
	}
	else{
		Node new_node = (Node)malloc(sizeof(struct Node));
		Node tmp = NULL;
		int count = 1;
		tmp = start;
		while(tmp != NULL){
			if((count + 1) == pos){
				new_node->data = element;
				new_node->link = tmp->link;
				tmp->link = new_node;
				return start;
			}
			else{
				tmp = tmp->link;
				count++;
			}
		}
		printf("Error in adding element %d at position %d. \n",element,pos);
		return start;
	}
}

// function to delete a particular node from the list
Node delete_element(Node start, int element){
	Node tmp = NULL;
	Node next = NULL;
	int count = 1;
	int mismatch = 0;
	tmp = start;
	next = tmp->link;
	printf("Deleting node %d from the list.... \n",element);
	while(tmp != NULL){
		if(next->data == element){
			tmp->link = next->link;
			free(next);
			return start;
		}
		else{
			mismatch++;
			tmp = tmp->link;
			next = next->link;
		}
		count++;
	}
	// TODO: work on invalid delete operation
	if(count == mismatch){
		printf("Invalid element. Delete cannot be performed.\n");
	}
	return start;
}

// function to delete the first node of the list
Node delete_first_node(Node start){
	printf("Deleting the first node from the list....\n");
	Node tmp = NULL;
	tmp = start;
	start = start->link;
	free(tmp);
	return start;
	
}

// function to delete the last node from the list
Node delete_last_node(Node start){
	printf("Deleting the last node of the list.....\n");
	Node tmp = NULL;
	Node next = NULL;
	tmp = start;
	next = tmp->link;
	while(next->link != NULL){
		tmp = tmp->link;
		next = next->link;
	}
	tmp->link = NULL;
	free(next);
	return start;
}

// main code
int main(void){
	int choice = 0;
	int add_el = 0;
	int del_el = 0;
	int pos = 0;
	int chunk = 0;
	char confirm = NULL;
	Node start_point = NULL;

	
	while(1){
		printf("-------------------------------------------------\n");
		printf("0. Create the list\n");
		printf("1. Add at the beginning of the list\n2. Add at the end of the list\n");
		printf("3. Add at a particular position\n4. Delete an element from the list\n");
		printf("5. Delete the first element\n6. Delete the last element\n");
		printf("7. Sort the list in ascending order\n8. Sort the list in descending order\n");
		printf("9. Reverse the list\n10. Display the list\n");
		printf("11. Exit\n");
		printf("-------------------------------------------------\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			// Create the list
			case 0:	printf("You chose: Create the linked list\n");
				printf("Enter the element you wish to add: ");
				scanf("%d", &add_el);
				start_point = create_list(add_el);
				printf("Done.");
				break;


			// Add at the beginning
			case 1:	printf("You chose: Add an element at beginning\n");
				printf("Enter the element you wish to add: ");
				scanf("%d",&add_el);
				start_point = add_at_beg(start_point, add_el);
				printf("Done.");
				break;

			// Add at the end
			case 2:	printf("You chose: Add an element at the end of the list\n");
				printf("Enter the element you wish to add: ");
				scanf("%d",&add_el);
				start_point = add_at_end(start_point, add_el);
				printf("Done.");
				break;
			// Add at position 
			case 3:	printf("You chose: Add an element at a particular position\n");
				printf("Enter the element you wish to enter: ");
				scanf("%d",&add_el);
				printf("\nEnter the position where the new element should be entered: ");
				scanf("%d",&pos);
				start_point = add_at_pos(start_point, add_el, pos);
				printf("Done.");
				break;
			
			// Delete element
			case 4:	printf("You chose: Delete an element from a particular position\n");
				printf("Enter the element to be deleted: ");
				scanf("%d",&del_el);
				start_point = delete_element(start_point, del_el);
				printf("Done.");
				break;

			// Delete first element
			case 5:	printf("You chose: Delete the first element from the list\n");
				start_point = delete_first_node(start_point);
				printf("Done.\n");
				break;

			// Delete the last node
			case 6:	printf("You chose: Delete the last element from the list\n");
				start_point = delete_last_node(start_point);
				printf("Done.");
				break;

			// Sort ascending
			case 7:printf("You chose: Sort the list in ascending order\n");
				break;
			
			// Sort descending
			case 8:printf("You chose: Sort the list in descending order\n");
				break;

			// Reverse the list
			case 9:printf("You chose: Reverse the list\n");
				break;
			
			// Display the list
			case 10:printf("You chose: Display the list\n");
				display_list(start_point);
				break;

			// Exit the program
			case 11:printf("Are you sure you want to exit? (y/n)\n");
				scanf("%s",&confirm);
				if(confirm == 'Y' || confirm == 'y'){
					printf("Now exiting the program.\n");
					exit(0);
				}
				else{
					printf("Redirecting to the main menu...\n");
				}	
				break;

			default:printf("Please enter a valid option\n");
				break;
		}
		printf("\n");
	}
	return 0;
}
