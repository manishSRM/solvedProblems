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

int minDist(const VI &A, int first, int second) {
	int N = A.size();
	int prev = -1, dist;
	FOR (i, 0, N) {
		if (A[i] == first || A[i] == second) {
			if (prev == -1) {
				prev = i;
				continue;
			}
			if (A[i] != A[prev] && dist > (i - prev)) {
				dist = i - prev;
				prev = i;
			}
		}	
	}
	return dist;
}

int main() {
	int N, K, X, Y;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	SC(X); SC(Y);
	cout << minDist(A, X, Y) << endl;
	return 0;
}