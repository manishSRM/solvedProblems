#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

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

int CUT_ROD(const VI &P, int n) {
	if(!n) 
		return 0;
	int Q = INT_MIN;                             //exponential complexity of (2^N) ^ => power 
	EFOR(i, 1, n) {								//if N = 40 it takes several minutes or even convert to hour						
		Q = max(Q, P[i] + CUT_ROD(P, n - i));
	}
	return Q;
}

int MEMOIZED_CUT_ROD_AUX(const VI &revenue, int n, VI &r) {
	if(r[n] > 0)
		return r[n];
	int Q;
	if (!n) {
		Q = 0;
	} else {
		Q = INT_MIN;
		EFOR(i, 1, n) {
			Q = max(Q, revenue[i] + MEMOIZED_CUT_ROD_AUX(revenue, n - i, r));
		}
		r[n] = Q;	
	}
	return Q;
}

int MEMOIZED_CUT_ROD(const VI &revenue, int n) {
	VI r(n + 1, INT_MIN);		                       //store results of sub-problems (key of memoization)
	return MEMOIZED_CUT_ROD_AUX(revenue, n, r);
}

int BOTTOM_CUT_ROD(const VI &revenue, int n) {
	VI r(n + 1, 0);
	EFOR(i, 1, n) {
		int Q = INT_MIN;
		EFOR(j, 1, i) {
			Q = max(Q, revenue[j] + r[i - j]);
		}
		r[i] = Q;
	}
	return r[n];
}

int main () {
    int N = 10;
    VI revenue(N + 1);
    EFOR(i, 1, N) {
    	SC(revenue[i]);
    }
    printf("%d\n", CUT_ROD(revenue, N));
    printf("%d\n", MEMOIZED_CUT_ROD(revenue, N)); 
    printf("%d\n", BOTTOM_CUT_ROD(revenue, N));
    return 0;
}
