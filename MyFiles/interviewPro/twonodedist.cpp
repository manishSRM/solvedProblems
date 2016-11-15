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

int findLevel(TreeNode *temp, int key, int level) {
	if (temp == NULL) {
		return -1;
	}
	if (temp -> data == key) {
		return level;
	}
	int l = findLevel(temp -> left, key, level + 1);
	return (l != -1) ? l : findLevel(temp -> right, key, level + 1);
}

TreeNode *LCA(TreeNode *temp, int n1, int n2) {
	if (temp == NULL) {
		return  NULL;
	}
	if (temp -> data == n1 || temp -> data == n2) {
		return temp;
	}
	TreeNode *left_lca = LCA(temp -> left, n1, n2);
	TreeNode *right_lca = LCA(temp -> right, n1, n2);
	if (left_lca && right_lca) {
		return temp;
	}
	return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
	TreeNode *root = buildTree();
	int l1 = findLevel(root, 14, 0);
	int l2 = findLevel(root, 11, 0);
	int lca = LCA(root, 14, 11) -> data;
	int lca_level = findLevel(root, lca, 0);
	cout << (l1 + l2) - 2 * (lca_level) << endl; 
	return 0;
} 