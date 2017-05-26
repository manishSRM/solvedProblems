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
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(VI &A, int first, int last) {
    if (first > last) {
        return NULL;
    }
    int mid = (first + last) / 2;
    TreeNode *temp = new TreeNode(A[mid]);
    temp -> left = helper(A, first, (mid - 1));
    temp -> right = helper(A, (mid + 1), last);
    return temp;
}

TreeNode* buildTree(VI &A) {
    int n = A.size();
    return helper(A, 0, n - 1);
}

void inorder(TreeNode *temp) {
    if (temp == NULL) {
        return;
    }
    cout << temp -> val << " ";
    inorder(temp -> left);
    inorder(temp -> right);
    return;
}

int main() {
    int N;
    cin >> N;
    VI A(N);
    FOR (i, 0, N) {
        SC(A[i]);
    }
    TreeNode *root = buildTree(A);
    inorder(root);
    cout << endl;
    return 0;
}




