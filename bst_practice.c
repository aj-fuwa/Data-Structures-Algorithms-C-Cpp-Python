/*
 * Aim: To implement a Binary Search tree in C with the following features
 * 				add a node in the BST, 
 * 				delete a node from the BST,
 * 				search for a node in the BST,
 * 				display the BST
 * Date: 21.Mai 2020
 */

#include<stdio.h>
#include<stdlib.h>

// define the node
struct Node{
	struct Node* left;
	struct Node* right;
	int data;
};

typedef struct Node* Node;

// function to create the base node of the BST
Node create_bst(Node start, int element){
	start = (Node)malloc(sizeof(struct Node));
	start->data = element;
	start->left = NULL;
	start->right = NULL;
	return start;
}

// function to add nodes
Node add_node(Node start, int element){
	if(start == NULL){
		start = create_bst(start, element);
		return start;
	}
	else if(element < start->data){
		start->left = add_node(start->left, element);
	}

	else{
		start->right = add_node(start->right, element);
	}
	return start;
}

// fucntion for displaying the value of the node
void display_node(Node start){
	if(start != NULL){
		display_node(start->left);
		printf("Node value is: %d\n",start->data);
		display_node(start->right);
	}
}

// main code
int main(void){
	int choice = 0;
	int element = 0;
	char exit_choice;
	Node start_point = NULL;

	printf("++Binary search tree++\n");
	while(1){
		printf("--------------------------------------------------------------------------------");
		printf("Choose any one option from below: \n");
		printf("0. Create a BST\n1. Add a node to the BST\n");
		printf("2. Delete a node from the BST\n3. Search for a node in the BST\n");
		printf("4. Display the BST\n5. Exit the program\n");
		printf("Enter your choice: \n");
		scanf("%d",&choice);
		switch(choice){

			// create the BST
			case 0:	printf("You chose: create a BST\n");
				printf("Enter your base node value: ");
				scanf("%d",&element);
				start_point = create_bst(start_point, element);
				printf("\nDone.");
				break;

			// add a node
			case 1:	printf("You chose: add a node to the BST\n");
				printf("Enter your nodes value: ");
				scanf("%d",&element);
				start_point = add_node(start_point, element);
				printf("\nDone.");
				break;

			// TODO: delete a node
			case 2:	printf("You chose: delete a node from the BST\n");
				printf("Enter the node you want to delete: ");
				scanf("%d",&element);
				printf("\nDone.");
				break;

			// TODO: search
			case 3:	printf("You chose: search for a node in the BST\n");
				printf("Enter the element to be searched in the BST: ");
				scanf("%d",&element);
				printf("\nDone.");
				break;
			
			// display
			case 4: printf("You chose: display the BST\n");
				display_node(start_point);
				printf("\nDone.");
				break;

			// exit code
			case 5: printf("Are you sure you want to exit? (y\\n)\n");
				scanf("%s",&exit_choice);
				if(exit_choice == 'y' || exit_choice == 'Y'){
					printf("Exiting the program..\n");
					exit(0);
				}
				else{
					printf("Going back to the main menu.....\n");
				}
				break;

			default:printf("Please select a valid option. \n");
				break;


		}
		printf("\n");
		choice = 0;
	}
	return 0;
}
