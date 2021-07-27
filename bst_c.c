/*
Name: bst_c.c
Aim: To implement the Binary Search Tree in C
Date: 27.July 2021
Functions included:   adding a node, creating a node, 
                      preorder, postorder, inorder
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left, *right;
};

typedef struct Node* node;

node new_node(int data){
  node root = (node)malloc(sizeof(struct Node));
	root->left = root->right = NULL;
	root->data = data;
	return root;
}

node add_node(node root, int data){
	if(root == NULL){
		return new_node(data);
	}
	else if(root->data < data){
		root->right = add_node(root->right, data);
	}
	else{
		root->left = add_node(root->left, data);
	}
	return root;
}

void inorder(node root){
	if (root != NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

void preorder(node root){
	if(root != NULL){
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}

int main(){
	node root = NULL;
	root = add_node(root, 50);
	root = add_node(root, 60);
	root = add_node(root, 40);
	postorder(root);
	return 0;
}
