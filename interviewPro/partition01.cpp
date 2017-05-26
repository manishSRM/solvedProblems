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

void seperateZeroOne(VI &A) {
	int N = A.size();
	int l = 0, r = N - 1;
	while (l < r) {
		if (A[l] == 1 && A[r] == 0) {
			A[l] = 0;
			A[r] = 1;
			l++;
			r--;
		} else if (A[l] == 1) {
			r--;
		} else {
			l++;
		}
	}
}

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	seperateZeroOne (A);
	FOR (i, 0, N) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}