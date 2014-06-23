#include <iostream>
#include <cstdio>
#include <stdlib.h>
 
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
};

TreeNode *createNode (int num) {
    TreeNode *temp = (TreeNode *)malloc(sizeof (TreeNode));
    temp -> data = num;
    temp -> left = temp -> right = NULL;
    return temp;
}

void inorderTravel (TreeNode *root) {
    if(root != NULL) {
        inorderTravel (root -> left);
        printf ("%d ", root -> data);
        inorderTravel (root -> right);
    } 
}

void preorderTravel (TreeNode *root) {
    if (root != NULL){
        printf ("%d ", root -> data);
        preorderTravel (root -> left);
        preorderTravel (root -> right);
    }
}

void postorderTravel (TreeNode *root) {
    if (root != NULL) {
        postorderTravel (root -> left);
        postorderTravel (root -> right);
        printf ("%d ", root -> data);
    }
}

int sumOfNodes (TreeNode *root) {
	if (root == NULL)
		return root -> data;
	//printf("%d\n", root -> data);
	int sum1 = sumOfNodes (root -> left);
	int sum2 = sumOfNodes (root -> right);

	return sum1 + sum2;
}

int main ()
{
    TreeNode *root = createNode (2);
    root -> left = createNode (7);
    root -> right = createNode (5);
    root -> left -> left = createNode (2);
    root -> left -> right = createNode (6);
    root -> left -> right -> left = createNode (5);
    root -> left -> right -> right = createNode (11);
    root -> right -> right = createNode (9);
    root -> right -> right -> left = createNode (4); 
    //inorderTravel (root);
   // preorderTravel (root);
   // postorderTravel (root);
    printf("%d\n", sumOfNodes (root));;
    return 0;
}