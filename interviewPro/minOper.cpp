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

int currentNumOper(int X, int Y) {
	if (Y > X) {
		return currentNumOper(Y, X);
	}
	if (Y == 0) {
		return -1;
	}
	if (Y == 1) {
		return X - 1;
	}
	int ret = currentNumOper(Y, X % Y);
	if (ret != -1) {
		ret += X / Y;
	}
	return ret;
}

int minOperation(int n) {
	if (n == 1) {
		return 0;
	}
	int oper = INT_MAX;
	for (int i = 1; i < n; i++) {
		int ret = currentNumOper(n, i);
		if (ret != -1 && ret < oper) {
			oper = ret;
		}
	}
	return oper;
}

int main() {
	int T, N;
	SC(T);
	while (T--) {
		SC(N);
		cout << minOperation(N) << endl;
	}
	return 0;
}
