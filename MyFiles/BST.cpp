#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node *root = NULL;

Node *createNewNode (int item) {
	NOde *ptr = (NOde *)malloc(sizeof(Node));
	ptr -> data = item;
	ptr -> left = ptr -> right = NULL;
	return ptr;
}

// void insertNode (Node *ptr) {
	
// }

void inorderTreeWalk (Node *root) {
	if (root != NULL) {
		inorderTreeWalk (root -> left);
		printf("%d ", root -> data);
		inorderTreeWalk (root -> right);
	}
}
 
int main () 
{
	int num;
	for (int i = 1; i < 10; i++) {
		scanf ("%d", &num);
		Node *temp = createNewNode (num);
		insertNode (temp);
	}
	inorderTreeWalk (root);
	return 0;
}