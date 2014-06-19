#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *createNode (int i) {
    node *x = (node *) malloc (sizeof(node));
    x->data = i;
    x->left = x->right = NULL;
}

node *root = NULL;

void insertNode (int a) {	
	
}

void inorder (node *temp) {
    if (temp != NULL) {
        inorder (temp -> left);
        printf ("%d\n", temp -> data);
        inorder (temp -> right);
    }
}

void preorder (node *temp) {
    if (temp != NULL) {
		printf ("%d\n", temp -> data);
		preorder (temp -> left);
		preorder (temp -> right);
	}
}

void postorder (node *temp) {
	if (temp != NULL) {
	postorder (temp -> left);
	postorder (temp -> right);
	printf ("%d\n", temp -> data);    
	}
}

int countNodes (node *temp) {
	int c = 1;   
    if (temp == NULL)
		return 0;
	else {
		c += countNodes (temp -> left);
		c += countNodes (temp -> right);
	}
	return c;	 	
}

int countLeaves (node *temp) {
	
}

int find_node (node *temp, int d) {
	int result = 0;
	if (temp == NULL) 
		return result;
	if (d > temp -> data)
		find_node (temp -> right, d);
	else if (d < temp -> data)
		find_node (temp -> left, d);
	else if (d == temp -> data)
		result = 1;
	return result;
    //return 1 if found, 0 if not
}

int destroy_tree (node *temp) {
    if (temp == NULL)	
		return 0;
	else {
		destroy_tree (temp -> left);
		destroy_tree (temp -> right);
		free (temp);
	}
	return 1;	
}

int main () {
    root = createNode(5);
    root -> left = createNode(7);
    root -> right = createNode(8);
    root -> left -> left = createNode(9);
    root -> left -> right = createNode(10);
    root -> right -> left = createNode(11);
    root -> right -> right = createNode(12);
    root -> right -> left -> right = createNode(15);
    root -> right -> right -> left = createNode(13);
    inorder (root);
    // postorder (root);
    // preorder (root);
	//printf ("%d\n", countNodes (root));
	//printf ("%d\n", countLeaves(root));    
	//printf ("%d\n", find_node(root, 13));	
	printf ("%d\n", destroy_tree(root));	
	return 0;
}
/*
                    5
            7               8
        9       10    11         12
                        15    13                        

9
7
10
5
11
8
12*/

