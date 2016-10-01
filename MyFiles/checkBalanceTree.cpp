#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
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
#define PF(A) printf("%d", A)

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
};

TreeNode *createNewNode(int data) {
    TreeNode *temp = new TreeNode;
    temp -> val = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

TreeNode *createTree() {
    TreeNode *p = createNewNode(1);
    TreeNode *t = createNewNode(2);
    p -> left = t;
    t = createNewNode(5);
    p -> right = t;
    t = createNewNode(3);
    p -> left -> left = t;
    t = createNewNode(4);
    p -> left -> left -> left = t;
    t = createNewNode(6);
    p -> right -> right = t;
    t = createNewNode(7);
    p -> right -> right -> right = t;
    return p;
}

int getHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

int checkHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = checkHeight(root -> left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = checkHeight(root -> right);
    if (rightHeight == -1) {
        return -1;
    }
    int heightDiff = leftHeight - rightHeight;
    if (abs(heightDiff) > 1) {
        return -1;
    } else {
        return max(checkHeight(root -> left), checkHeight(root -> right)) + 1;
    }
}

bool isBalanced(TreeNode *root) {
    if (checkHeight(root) == -1) {
        return 0;
    }
    return 1;
}

int main() {
    TreeNode *root = createTree();
    cout << isBalanced(root) << endl;
    return 0;
}






