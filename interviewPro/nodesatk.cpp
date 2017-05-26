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
#define MAX_SIZE 10000
using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* createNewNode(int val) {
	TreeNode *temp = new TreeNode;
	temp -> data = val;
	temp -> right = NULL;
	temp -> left = NULL;
}

TreeNode* buildTree() {
	TreeNode *root = createNewNode(1);
	root -> left = createNewNode(2); 	
	root -> right = createNewNode(3);
	root -> left -> left = createNewNode(4);
	root -> left -> right = createNewNode(5);
	root -> right -> left = createNewNode(6);
	root -> right -> right = createNewNode(7);
	root -> right -> left -> right = createNewNode(8);
	root -> left -> left -> left = createNewNode(9);
	root -> left -> left -> right = createNewNode(10);
	root -> left -> left -> right -> left = createNewNode(11);
	root -> left -> right -> left = createNewNode(12);
	root -> right -> right -> left = createNewNode(16);
	root -> right -> right -> right = createNewNode(13);
	root -> right -> right -> right -> left = createNewNode(14);
	root -> right -> right -> right -> right = createNewNode(15);
	return root;
}
 
void nodesAtKdistancefromLeaf(TreeNode *temp, VI &A, VB &visited, int pathLen, int k) {
	if (temp == NULL) {
		return;
	}
	A[pathLen] = temp -> data;
	visited[pathLen] = false;
	pathLen++;

	if(temp -> left == NULL && temp -> right == NULL && pathLen - k - 1 >= 0 && visited[pathLen - k - 1] == false) {
		cout << A[pathLen - k - 1] << endl;
		visited[pathLen - k - 1] = true;
		return;
	}
	nodesAtKdistancefromLeaf(temp -> left, A, visited, pathLen, k);
	nodesAtKdistancefromLeaf(temp -> right, A, visited, pathLen, k);
}

int main() {
	TreeNode *root = buildTree();
	VI A(MAX_SIZE);
	VB visited(MAX_SIZE);
	nodesAtKdistancefromLeaf(root, A, visited, 0, 2);
	return 0;
} 