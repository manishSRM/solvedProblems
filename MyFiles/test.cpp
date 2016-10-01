#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createNewNode(int data) {
    TreeNode *temp = new TreeNode(data);
    return temp;
}

TreeNode *createTree() {
    TreeNode *p = createNewNode(1);
    TreeNode *t = createNewNode(2);
    p -> left = t;
    t = createNewNode(5);
    p -> right = t;
    t = createNewNode(4);
    p -> left -> right = t;
    // t = createNewNode(13);
    // p -> right -> left = t;
    t = createNewNode(3);
    p -> left -> left = t;
    t = createNewNode(6);
    p -> right -> right = t;
    // t = createNewNode(6);
    // p -> left -> right -> left = t;
    // t = createNewNode(8);
    // p -> left -> left -> right -> left = t;
    // t = createNewNode(13);
    // p -> right -> left = t;
    // t = createNewNode(14);
    // p -> right -> left -> right = t;
    return p;
}

void printInOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root -> left);
    printf("%d\n", root -> val);
    printInOrder(root -> right);
}

TreeNode *buildTree(VI &inOrder, VI &preOrder, int first, int last, int &preIndex) {
    if (first > last) {
        return NULL;
    }
    TreeNode *temp = new TreeNode((preOrder[preIndex++]));

    if (first == last) {
        return temp;
    }
    int index = search(inOrder, first, last, temp -> val);
    temp -> left = buildTree(inOrder, preOrder, first, (index - 1), preIndex);
    temp -> right = buildTree(inOrder, preOrder, (index + 1), last, preIndex);
    return temp;
}

int search(VI &inOrder, int first, int last, int value) {
    for (int i = first; i <= last; i++) {
        if (inOrder[i] == value) {
            return i;
        }
    }
    return -1;
}

bool checkBST(TreeNode *n, int &last_print) {
    if (n == NULL) {
        return 1;
    }
    if(!checkBST(n -> left, last_print)) {
        return 0;
    }

    if (last_print == INT_MIN && n -> val == last_print) {
        return 0;
    }

    if (last_print != INT_MIN && n -> val <= last_print) {
        return 0;
    }
    last_print = n -> val;

    if (!checkBST(n -> right, last_print)) {
        return 0;
    }
    return 1;
}

int main() {
    int N, K;
    SC(N);
    FOR(i, 0, N) {
        SC(K);

    }
    return 0;
}




