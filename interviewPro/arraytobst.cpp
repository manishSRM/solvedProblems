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
#define SCL(A) scanf("%lld", &A)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)
#define MOD 1000000007

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

void printInorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    printInorder(root->left);
    printInorder(root->right);
    return;
}

void insertInBST(int value, TreeNode **temp) {
    if (*temp == NULL) {
        *temp = new TreeNode(value);
        return;
    }
    if (value <= (*temp) -> val) {
        insertInBST(value, &((*temp) -> left));
    } else {
        insertInBST(value, &((*temp) -> right));
    }
}

TreeNode* buildBST(const VI &A) {
    int size = A.size();
    if (!size) {
        return NULL;
    }
    TreeNode *root = new TreeNode(A[0]);
    for (int i = 1; i < size; i++) {
        insertInBST(A[i], &root);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    VI A(n);
    FOR (i, 0, n) {
        SC(A[i]);
    }
    TreeNode *root = buildBST(A);
    printInorder(root);
    cout << endl;
    return 0;
}

