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
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* builTree() {
	TreeNode *root = new TreeNode(10);
	root -> left =  new TreeNode(5);
	root -> right = new TreeNode(15);
	root -> left -> left = new TreeNode(3);
	root -> left -> right = new TreeNode(7);
	root -> right -> right = new TreeNode(20);
	root -> right -> left = new TreeNode(11);
	// root -> left -> left -> left = new TreeNode(7);
	root -> left -> left -> right = new TreeNode(4);
	root -> right -> left -> right = new TreeNode(12);
	root -> right -> right -> left = new TreeNode(18);
	root -> left -> right -> left = new TreeNode(6);
	root -> left -> right -> right = new TreeNode(8);
	return root;
}

// int treeSize(TreeNode *root) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	int lnodes = treeSize(root -> left);
// 	int rnodes = treeSize(root -> right);

// 	return (lnodes + rnodes + 1);
// }

// void makeMirriorTree(TreeNode *root) {
// 	if (root) {
// 		makeMirriorTree(root -> left);
// 		makeMirriorTree(root -> right);

// 		TreeNode *temp = root -> left;
// 		root -> left = root -> right;
// 		root -> right = temp;
// 	}
// }

// bool isChilderSumPrepertyExist(TreeNode *root) {
// 	int l_d = 0, r_d = 0;
// 	if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
// 		return 1;
// 	}

// 	if (root -> left != NULL) {
// 		l_d = root -> left -> val;
// 	}
// 	if (root -> right != NULL) {
// 		r_d = root -> right -> val;
// 	}
// 	if ((root -> val == l_d + r_d) & isChilderSumPrepertyExist(root -> left) & isChilderSumPrepertyExist(root -> right)) {
// 		return 1;
// 	return 0;
// }

// int checkHeight(TreeNode *root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int leftHeight = checkHeight(root -> left);
//     if (leftHeight == -1) {
//         return -1;
//     }
//     int rightHeight = checkHeight(root -> right);
//     if (rightHeight == -1) {
//         return -1;
//     }
//     int heightDiff = leftHeight - rightHeight;
//     if (abs(heightDiff) > 1) {
//         return -1;
//     } else {
//         return max(checkHeight(root -> left), checkHeight(root -> right)) + 1;
//     }
// }

// bool isBalanced(struct TreeNode *root) {
//     if (checkHeight(root) == -1) {
//         return 0;
//     }
//     return 1;
// }

// bool hasPathSum(TreeNode *root, int curSum) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	if (root -> val > curSum) {
// 		return 0;
// 	}
// 	if (root -> left == NULL && root -> right == NULL && root -> val == curSum) {
// 		return 1;
// 	}
// 	//cout << root -> val << " " << curSum << endl;
// 	return (hasPathSum(root->left, (curSum - root->val)) || hasPathSum(root->right, (curSum - root->val)));
// }

// void makeDupleTree(TreeNode *temp) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	if (temp -> left == NULL) {
// 		temp -> left = new TreeNode(temp -> val);
// 	} else {
// 		TreeNode *t1 = temp -> left;
// 		temp -> left = new TreeNode(temp -> val);
// 		temp -> left -> left = t1;
// 	}
// 	makeDupleTree(temp -> left -> left);
// 	makeDupleTree(temp -> right);
// }

// void nodesAtDistanceKFromRoot(TreeNode *temp, int K, int currentHeight) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	if (currentHeight == K) {
// 		cout << temp -> val << endl;
// 	}
// 	nodesAtDistanceKFromRoot(temp -> left, K, currentHeight + 1);
// 	nodesAtDistanceKFromRoot(temp -> right, K, currentHeight + 1);
// }

// void levelOrder(TreeNode *temp) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	queue<TreeNode *> Q;
// 	Q.push(temp);
// 	while (!Q.empty()) {
// 		TreeNode *t = Q.front();
// 		Q.pop();
// 		cout << t -> val << " ";
// 		if (t -> left != NULL) {
// 			Q.push(t -> left);
// 		}
// 		if (t -> right != NULL) {
// 			Q.push(t -> right);
// 		}
// 	}
// 	cout << endl;
// 	return;
// }

// vector<int> iterativeInorder(TreeNode* A) {
// 	if (A == NULL) {
// 		return vector<int> ();
// 	}
// 	stack<TreeNode *> S;
// 	vector<int> V;
// 	bool done = false;
// 	while (!done) {
// 		if (A != NULL) {
// 			S.push (A);
// 			A = A -> left;
// 		} else if (!S.empty()) {
// 			A = S.top();
// 			S.pop();
// 			V.push_back(A -> val);
// 			A = A -> right;
// 		} else {
// 			done = true;
// 		}
// 		cout << (S.top()) -> val << endl;
// 	}
// 	return V;
// }

// void iterativePreorder(TreeNode *temp) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	stack<TreeNode *> S;
// 	S.push(temp);
// 	while (!S.empty()) {
// 		TreeNode *t = S.top();
// 		S.pop();
// 		cout << t -> val << " ";
// 		if (t -> right) {
// 			S.push(t -> right);
// 		}
// 		if (t -> left) {
// 			S.push(t -> left);
// 		}
// 	}
// 	cout << endl;
// 	return;
// }

// void iterativePostorder(TreeNode *temp) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	stack<TreeNode *> S1;
// 	stack<int> S2;
// 	S1.push(temp);
// 	while (!S1.empty()) {
// 		TreeNode *t = S1.top();
// 		S1.pop();
// 		S2.push(t -> val);
// 		if (t -> left) {
// 			S1.push(t -> left);
// 		}
// 		if (t -> right) {
// 			S1.push(t -> right);
// 		}
// 	}
// 	while (!S2.empty()) {
// 		cout << S2.top() << " ";
// 		S2.pop();
// 	}
// 	cout << endl;
// 	return;
// }

// vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
// 	if (root == NULL) {
// 		return vector<vector<int> >();
// 	}
// 	vector<vector<int> > V;
// 	queue<TreeNode *> Q;
// 	Q.push(root);
// 	bool leftRight = true;
// 	while (!Q.empty()) {
// 		int size = Q.size();
// 		vector<int> R(size);
// 		for (int i = 0; i < size; i++) {
// 			TreeNode *temp = Q.front();
// 			Q.pop();
// 			int index = (leftRight) ? i : (size - i - 1);
// 			R[index] = temp -> val;
// 			if (temp -> left) {
// 				Q.push(temp -> left);
// 			}
// 			if (temp -> right) {
// 				Q.push(temp -> right);
// 			}
// 		}
// 		leftRight = !leftRight;
// 		V.push_back(R);
// 	}
// 	return V;
// }

// void printAllAncestors(TreeNode *temp, VI A, int key) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	if (temp -> val == key) {
// 		displayPath(A);
// 	}
// 	A.push_back(temp -> val);
// 	printAllAncestors(temp -> left, A, key);
// 	printAllAncestors(temp -> right, A, key);
// 	return;
// }

// bool isLeafLevelSame(TreeNode *temp, int level, int *prev) {
// 	if (temp == NULL) {
// 		return true;
// 	}
// 	if (temp -> left == NULL && temp -> left == NULL) {
// 		if (*prev == -1) {
// 			*prev = level;
// 			return true;
// 		}
// 		return (level == *prev);
// 	}
// 	return (isLeafLevelSame(temp -> left, level + 1, prev) && isLeafLevelSame(temp -> right, level + 1, prev));
// }

// bool isBSTUtil(TreeNode *root, int min, int max) {
// 	if (root == NULL) {
// 		return 1;
// 	}
// 	if (root -> val < min || root -> val > max) {
// 		return 0;
// 	}
// 	return (isBSTUtil(root -> left, min, root -> val - 1) && isBSTUtil(root -> right, root -> val + 1, max));
// }

// bool isBST(TreeNode *root) {
// 	return(isBSTUtil(root, INT_MIN, INT_MAX));
// }


// TreeNode *find(TreeNode *temp, int N) {
// 	if (temp -> val == N) {
// 		return temp;
// 	}
// 	return (temp -> val > N) ? find(temp -> left, N) : find(temp -> right, N);
// }

// TreeNode *getSuccessor(TreeNode* A, int B) {
// 	TreeNode *currentNode = find(A, B);
// 	if (currentNode -> right != NULL) {
// 		TreeNode  *ptr = currentNode -> right;
// 		while (ptr -> left != NULL) {
// 			ptr = ptr -> left;
// 		}
// 		return ptr;
// 	} else {
// 		TreeNode *successor = NULL;
// 		TreeNode *ancestor = A;
// 		while (ancestor != currentNode) {
// 			if (ancestor -> val > B) {
// 				successor = ancestor;
// 				ancestor = ancestor -> left;
// 			} else {
// 				ancestor = ancestor -> right;
// 			}
// 		}
// 		return successor;
// 	}
// }

// void displayPath(VI &temp) {
// 	FOR(i, 0, temp.size()) {
// 		cout << temp[i] << " ";
// 	}
// 	cout << endl;
// }

// void allpathsRoot_leaf(TreeNode *temp, VI A) {
// 	if (temp == NULL) {
// 		return;
// 	}
// 	A.push_back(temp -> val);
// 	if (temp -> left == NULL && temp -> right == NULL) {
// 		displayPath(A);
// 	} else {
// 		allpathsRoot_leaf(temp -> left, A);
// 		allpathsRoot_leaf(temp -> right, A);
// 	}
// }

// bool isSum(TreeNode *A, int sum) {
// 	if (A == NULL) {
// 		return false;
// 	}
// 	if (A -> left == NULL && A -> right == NULL) {
// 		return A -> val == sum;
// 	}
// 	int remain = sum - A -> val;
// 	return (isSum(A -> left, remain) || isSum(A -> right, remain));
// }

// void helper(TreeNode *root, int remainSum, vector<vector<int> > &ans, vector<int> temp) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	temp.push_back(root -> val);
// 	if (remainSum == root -> val && (root -> left == NULL && root -> right == NULL)) {
// 		ans.push_back(temp);
// 		return;
// 	}
// 	helper(root -> left, (remainSum - (root -> val)), ans, temp);
// 	helper(root -> right, (remainSum - (root -> val)), ans, temp);
// 	return;
// }

// vector<vector<int> > pathSum(TreeNode* root, int sum) {
// 	if (root == NULL) {
// 		return vector<vector<int> >();
// 	}
// 	vector<vector<int> > ans;
// 	vector<int> temp;
// 	helper(root, sum, ans, temp);
// 	return ans;
// }

// int diameterutil(TreeNode *root, int &maxAns) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	int l = diameterutil(root -> left, maxAns);
// 	int r = diameterutil(root -> right, maxAns);
// 	maxAns = (l+r) > maxAns ? (l+r) : maxAns;
// 	return max(diameterutil(root -> left, maxAns), diameterutil(root -> right, maxAns)) + 1;
// }

// int diameter(TreeNode *root) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	int maxAns = -1;
// 	int dummy = diameterutil(root, maxAns);
// 	return maxAns + 1;
// }

// void rightViewUtil(TreeNode *root, int cur, int &uniqueFirst) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	if (uniqueFirst == (cur - 1)) {
// 		cout << (root -> val) << " ";
// 		uniqueFirst = cur;
// 	}
// 	rightViewUtil(root->right, cur+1, uniqueFirst);
// 	rightViewUtil(root->left, cur+1, uniqueFirst);
// }

// void rightView(TreeNode *root) {
// 	int cur = 0, uniqueFirst = -1;
// 	rightViewUtil(root, cur, uniqueFirst);
// }

// void Util(TreeNode *root, int k, int cur) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	if (k == cur) {
// 		cout << root->val << " ";
// 	}
// 	Util(root -> left, k, cur+1);
// 	Util(root -> right, k, cur+1);
// }

// void printKdistance(struct TreeNode *root, int k) {
// 	int cur = 0;
// 	Util(root, k, cur);
// }

// TreeNode *LCA(TreeNode *root, int n1, int n2) {
// 	if (root == NULL) {
// 		return NULL;
// 	}
// 	if (root -> val == n1 || root -> val == n2) {
// 		return root;
// 	}
// 	TreeNode *left_lca = LCA(root -> left, n1, n2);
// 	TreeNode *right_lca = LCA(root -> right, n1, n2);
// 	if (left_lca && right_lca) {
// 		return root;
// 	}
// 	TreeNode *childTree = (left_lca) ? left_lca : right_lca;
// 	return LCA(childTree, n1, n2);
//  }

// void inorder(TreeNode *root) {
// 	if (root) {
// 		inorder(root -> left);
// 		cout << root -> val << " ";
// 		inorder(root -> right);
// 	}
// }

// void convertTreeToChildSumProperty(TreeNode *root) {                   // bottom up approach
// 	if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
// 		return;
// 	}
// 	convertTreeToChildSumProperty(root -> left);
// 	convertTreeToChildSumProperty(root -> right);
// 	int l = 0, r = 0;
// 	if (root -> left != NULL) {
// 		l = root -> left -> val;
// 	}
// 	if (root -> right != NULL) {
// 		r = root -> right -> val;
// 	}
// 	root -> val = (l + r);
// 	return;
// }

// int travel(TreeNode *root, bool &ans) {
// 	if (root == NULL)
// 		return 0;
// 	if (root -> left == NULL && root -> right == NULL)
// 		return (root->val);
// 	int l = travel(root->left, ans);
// 	int r = travel(root->right, ans);
// 	if (l+r != root->val)
// 		ans = false;
// 	return (l + r + root -> val);
// }

// bool isSumTree(TreeNode *root) {
// 	bool ans = true;
// 	travel(root, ans);
// 	return ans;
// }

// void inOrder(TreeNode *root, int l, int h, int &count) {                   // print in range [l, h]
// 	if (root == NULL) {
// 		return;
// 	}
// 	if (root->val >= l && root->val <= h) {
// 		inOrder(root->left, l, h, count);
// 		count++;
// 		inOrder(root->right, l, h, count);
// 	} else if (root->val <= l) {
// 		inOrder(root->right, l, h, count);
// 	} else if (root->val >= h) {
// 		inOrder(root->left, l, h, count);
// 	}
// }

void changeBST(TreeNode *root, int &help) {
	if (root == NULL)
		return;
	changeBST(root->right, help);
	root -> val += help;
	help = root->val;
	changeBST(root->left, help);
}

void inOrder(TreeNode *root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

int main() {
	TreeNode *root = builTree();
	int help = 0;
	changeBST(root, help);
	inOrder(root);
	cout << endl;
	return 0;
}




