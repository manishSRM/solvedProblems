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
#define MOD 1000000007
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
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree() {
    TreeNode *root = new TreeNode(8);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(10);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(7);
    root -> right -> right = new TreeNode(12);
    root -> right -> left = new TreeNode(9);
    root -> left -> right -> left = new TreeNode(6);
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode *root, int first, int second) {
    if (root == NULL) {
        return NULL;
    }
    if (root -> val == first || root -> val  == second) {
        return root;
    }
    TreeNode *left_lca = lowestCommonAncestor(root -> left, first, second);
    TreeNode *right_lca = lowestCommonAncestor(root -> right, first, second);
    if (left_lca && right_lca) {
        return root;
    }
    return (left_lca == NULL) ? right_lca : left_lca;
}

int main() {
    int first, second;
    cin >> first >> second;
    TreeNode *root = buildTree();
    TreeNode *ancestor = lowestCommonAncestor(root, first, second);
    cout << ancestor -> val << endl;
    return 0;
}






