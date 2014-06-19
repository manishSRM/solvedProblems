#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;

struct node {
	int data;
	node *right;
	node *left;
};

node *root = NULL;

node *createNode (int i) {
    node *temp = (node *) malloc (sizeof(node));
    temp -> data = i;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void insert (int value) {
	if (root == NULL) {
	  node *ptr = createNode (value);
	  root = ptr;
	}     
	else {
		node *ptr = createNode (value);

	}
}

void initalizeTree ()

void inorderPrint (node *temp) {
	if ( temp != NULL ) {  
		inorderPrint ( temp -> left );    
        printf ("%d", temp -> data);     
        inorderPrint ( temp -> right );   
    }
} 


int main() {
	int array[50];
	for (int i = 0; i < 10; i++) {
		scanf ("%d", &array [i]);
	}

	inorderPrint (root);
	
	return 0;
}
