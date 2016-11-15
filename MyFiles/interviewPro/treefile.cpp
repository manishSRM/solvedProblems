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
	Treenode *root = createNewNode(1);
	root -> left = createNewNode(2);
	root -> right = createNewNode(3);
	root -> left -> left = createNewNode(4);
	root -> left -> left -> right = createNewNode(5);
	root -> left -> left -> right -> left = createNewNode(6);
	root -> right -> left = createNewNode(9);
	root -> left -> right = createNewNode(7);
	root -> left -> right -> right = createNewNode(8);
	root -> left -> right -> right -> right = createNewNode(10);
	root -> left -> right -> right -> right -> left = createNewNode(11);
	return root;
}

int treeSize(Treenode *root) {
	if (root == NULL) {
		return 0;
	}
	int lnodes = treeSize(root -> left);
	int rnodes = treeSize(root -> right);

	return (lnodes + rnodes + 1);
}

void inorder(Treenode *temp) {
	if (temp) {
		inorder(temp -> left);
		printf("%d\n", temp -> data);	
		inorder(temp -> right);
	}
}

void makeMirriorTree(Treenode *root) {
	if (root) {
		makeMirriorTree(root -> left);
		makeMirriorTree(root -> right);	
		
		Treenode *temp = root -> left;
		root -> left = root -> right;
		root -> right = temp;
	}
} 

void displayPath(VI &temp) {
	FOR(i, 0, temp.size()) {
		cout << temp[i] << " ";
	}
	cout << endl;
}

void allpathsRoot_leaf(Treenode *temp, VI A) {
	if (temp == NULL) {
		return;
	}
	A.push_back(temp -> data);
	if (temp -> left == NULL && temp -> right == NULL) {
		displayPath(A);
	} else {
		allpathsRoot_leaf(temp -> left, A);
		allpathsRoot_leaf(temp -> right, A);
	} 
}

bool isChilderSumPrepertyExist(Treenode *root) {
	int l_d = 0, r_d = 0;
	if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
		return 1;
	} 
	
	if (root -> left != NULL) {
		l_d = root -> left -> data;
	}	
	if (root -> right != NULL) {
		r_d = root -> right -> data;
	}
	if ((root -> data == l_d + r_d)&isChilderSumPrepertyExist(root -> left)&isChilderSumPrepertyExist(root -> right)) {
		return 1;
	} else {
		return 0;
	}
} 

Treenode *builTree2() {
	Treenode *root = createNewNode(1);
	root -> right = createNewNode(3);
	root -> left = createNewNode(2);
	root -> left -> left = createNewNode(4);
	root -> left -> right = createNewNode(5);
	root -> right -> left = createNewNode(6);
	root -> right -> right = createNewNode(7);
	root -> right -> right -> left = createNewNode(10);
	root -> left -> left -> left = createNewNode(8);
	root -> left -> right -> right = createNewNode(9);
	//root -> left -> right -> right -> left = createNewNode(11);
	return root;
}

void ifNegative(Treenode *root, int diff) {
	if (root -> left != NULL) {
		root -> left -> data += diff;
		ifNegative(root -> left, diff);
	} else if (root -> right != NULL) {
		root -> right -> data += diff;
		ifNegative(root -> right, diff);
	}
}

void convertTreeToChildSumProperty(Treenode *root) {
	int ld = 0, rd = 0, diff;
	if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
		return;
	}
	convertTreeToChildSumProperty(root -> left);
	convertTreeToChildSumProperty(root -> right);

	if (root -> left != NULL) {
		ld = root -> left -> data;
	}
	if (root -> right != NULL) {
		rd = root -> right -> data;
	}
	diff = ld + rd - root -> data;
	if (diff > 0) {
		root -> data += diff;
	} 
	if (diff < 0) {
		ifNegative(root, -diff);
	}
	return;
}

int heightOfTree(Treenode *temp) {
	if (temp == NULL) {
		return 0;
	}
	int l_h = heightOfTree(temp -> left);
	int r_h = heightOfTree(temp -> right);

	return (max(l_h, r_h) + 1);
}

bool checkHeightBalanced(Treenode *temp) {
	if (temp == NULL) {
		return 0;
	}
	int l1 = heightOfTree(temp -> left);
	int l2 = heightOfTree(temp -> right);

	if (abs(l1 - l2) < 2 && checkHeightBalanced(temp -> left) && checkHeightBalanced(temp -> right)) {
		return 1;
	}
	return 0;
}

void inorderWithoutRecursion(Treenode *temp) {
	stack<Treenode *> S;
	bool done = 0;
	while (!done) {
		if (temp != NULL) {
			S.push (temp);
			temp = temp -> left;
		} else {
			if (!S.empty()) {
				temp = S.top();
				S.pop();
				cout << temp -> data << endl;
				temp = temp -> right;
			} else {
				done = 1;
			}
		}
	}
}	

int hasPathSum(Treenode *root, VI A, int pathindex, int sum) {
	if (root == NULL) {
		return 0;
	} 
	A.push_back(A[pathindex - 1] + root -> data);
	pathindex++;
	if (root -> left == NULL && root -> right == NULL) {
		return (A[pathindex - 1] == sum) ? 1 : 0; 
	}
	int l1 = hasPathSum(root -> left, A, pathindex, sum);
	int r1 = hasPathSum(root -> right, A, pathindex, sum);
	return (l1 + r1 > 0) ? 1 : 0;
}

void makeDupleTree(Treenode *temp) {
	if (temp == NULL) {
		return;
	}
	if (temp -> left == NULL) {
		temp -> left = createNewNode(temp -> data);
	} else {
		Treenode *t1 = temp -> left;
		temp -> left = createNewNode(temp -> data);
		temp -> left -> left = t1;
	}
	makeDupleTree(temp -> left -> left);
	makeDupleTree(temp -> right); 
}

void nodesAtDistanceKFromRoot(Treenode *temp, int K, int currentHeight) {
	if (temp == NULL) {
		return;
	}
	if (currentHeight == K) {
		cout << temp -> data << endl;
	}
	nodesAtDistanceKFromRoot(temp -> left, K, currentHeight + 1);
	nodesAtDistanceKFromRoot(temp -> right, K, currentHeight + 1);
}	

void levelOrder(Treenode *temp) {
	if (temp == NULL) {
		return;
	}
	queue<Treenode *> Q;
	Q.push(temp);
	while (!Q.empty()) {
		Treenode *t = Q.front();
		Q.pop();
		cout << t -> data << " ";
		if (t -> left != NULL) {
			Q.push(t -> left);
		}
		if (t -> right != NULL) {
			Q.push(t -> right);
		}
	}
	cout << endl;
	return;
}

void iterativePreorder(Treenode *temp) {
	if (temp == NULL) {
		return;
	}
	stack<Treenode *> S;
	S.push(temp);
	while (!S.empty()) {
		Treenode *t = S.top();
		S.pop();
		cout << t -> data << " ";
		if (t -> right) {
			S.push(t -> right);
		}
		if (t -> left) {
			S.push(t -> left);
		}	
	}
	cout << endl;
	return;
}

void iterativePostorder1(Treenode *temp) {
	if (temp == NULL) {
		return;
	}
	stack<Treenode *> S1;
	stack<int> S2;
	S1.push(temp);
	while (!S1.empty()) {
		Treenode *t = S1.top();
		S1.pop();
		S2.push(t -> data);
		if (t -> left) {
			S1.push(t -> left);
		}
		if (t -> right) {
			S1.push(t -> right);
		}
	}
	while (!S2.empty()) {
		cout << S2.top() << " ";
		S2.pop();
	}
	cout << endl;
	return;
}

void printAllAncestors(Treenode *temp, VI A, int key) {
	if (temp == NULL) {
		return;
	}
	if (temp -> data == key) {
		displayPath(A);
	}
	A.push_back(temp -> data);
	printAllAncestors(temp -> left, A, key);
	printAllAncestors(temp -> right, A, key);
	return;
}

bool isLeafLevelSame(Treenode *temp, int level, int *prev) {
	if (temp == NULL) {
		return true;
	}
	if (temp -> left == NULL && temp -> left == NULL) {
		if (*prev == -1) {
			*prev = level;
			return true;
		}
		return (level == *prev);
	} 
	return (isLeafLevelSame(temp -> left, level + 1, prev) && isLeafLevelSame(temp -> right, level + 1, prev));
}

int main() {
	Treenode *root = builTree2();
	//inorder(root);
	int prev = -1;
	cout << isLeafLevelSame(root, 0, &prev) << endl;
	return 0;
}  