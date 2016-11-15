#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <sstream>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <deque>
#include <bitset>
#include <map>
#include <assert.h>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

struct Treenode {
	int data;
	Treenode *left;
	Treenode *right;
};

Treenode *createNewNode(int val) {
	Treenode *temp = new Treenode;
	temp -> data = val;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

Treenode* builTree() {
	Treenode *root = NULL;
	Treenode *t = createNewNode(1);
	root = t;
	t = createNewNode(2);
	root -> left = t;
	t = createNewNode(3);
	root -> right = t;
	t = createNewNode(4);
	root -> left -> left = t;
	t = createNewNode(5);
	root -> left -> left -> right = t;
	t = createNewNode(6);
	root -> left -> left -> right -> left = t;
	t = createNewNode(9);
	root -> right -> left = t;
	t = createNewNode(7);
	root -> left -> right  = t;
	t = createNewNode(8);
	root -> left -> right -> right = t;
	t = createNewNode(10);
	root -> left -> right -> right -> right = t;
	t = createNewNode(11);
	root -> left -> right -> right -> right -> left = t;
	return root;
}

int heightOfTree(Treenode *root) {
	if (root == NULL) {
		return 0;
	} 
	int leftHeight = heightOfTree(root -> left);
	int rightHeight = heightOfTree(root -> right);

	return (1 + max(leftHeight, rightHeight));
}

int longestPathInTree(Treenode *root) {
	if (root == NULL) {
		return 0;
	}
	cout << root -> data << endl;
	int lHeight = heightOfTree(root -> left);
	int rHeight = heightOfTree(root -> right);

	cout << lHeight << " " << rHeight << " " << root -> data << endl;

	return max((lHeight + rHeight + 1), max(longestPathInTree(root -> left), longestPathInTree(root -> right)));
}	

int main() {
	Treenode* root = builTree();	
	cout << longestPathInTree(root) << endl;
	return 0;
}