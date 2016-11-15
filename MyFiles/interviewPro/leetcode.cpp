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

struct ListNode {
	int data;
	ListNode *next;
	ListNode(int x) : data(x), next(NULL) {}
};

TreeNode *createNewNodeWithVal(xint val) {
	TreeNode *temp = new TreeNode(val);
	return temp;
}

vector<int> inputArray() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	return A;
}

TreeNode *builTree2() {
	TreeNode *root = createNewNodeWithVal(1);
	root -> right = createNewNodeWithVal(3);
	root -> left = createNewNodeWithVal(2);
	root -> left -> left = createNewNodeWithVal(4);
	root -> left -> right = createNewNodeWithVal(5);
	root -> right -> left = createNewNodeWithVal(6);
	root -> right -> right = createNewNodeWithVal(7);
	root -> right -> right -> left = createNewNodeWithVal(10);
	root -> left -> left -> left = createNewNodeWithVal(8);
	root -> left -> right -> right = createNewNodeWithVal(9);
	return root;
}

void insertAtStart(ListNode *&head, int K) {
	ListNode *t = new ListNode(K);
	if (head == NULL) {
		head = t;
	} else {
		ListNode *temp = head;
		t -> next = temp;
		head = t;
	}
	return;
}

vector<int> productExceptSelf(vector<int>& nums) {
	if (!nums.size()) {
		return vector<int> ();
	}
	int size = nums.size();
	vector<int> B(size), C(size);
	B[0] = nums[0];
	C[size - 1] = nums[size - 1];
	for (int i = 1; i < size; i++) {
		B[i] = B[i - 1] * nums[i];
		C[size - i - 1] = C[size - i] * nums[size - i - 1];
 	}
	vector<int> result;
	result.push_back(C[1]);
	for (int j = 1; j < size; j++) {
		if (j + 1 < size) {
			result.push_back(B[j - 1] * C[j + 1]);
		} else {
			result.push_back(B[j - 1]);
		}
	}
	return result;
}

int GCD(int X, int Y) {
	if (X % Y == 0) {
		return Y;
	}
	return GCD(Y, X % Y);
}

int main() {
	cout << GCD(15, 6) << endl;
	return 0;
}
