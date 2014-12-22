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
#define SCC(A) scanf("%lld", &A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<lint,int> MP;

int isBitSet (int mask, int k) {
    return ((mask & (1 << k)) != 0);
}

int check(const vector<bool> &V, int n) {
	FOR(l, 0, n) {
		if(V[l] == false)
			return 0;
	}
	return 1;
}

int storeSubsetIndexes (const VLI& A, int n, lint requiredSum, int K) {
	int maxCount = 0;
	vector<bool> V(n, false);
	for(int mask = 1; mask < (1 << n); mask++) {
		lint Sum = 0;
		vector<int> S;
		for(int k = 0; k < n; k++) {
			if(isBitSet(mask, k)) {
				Sum += A[k];
				S.push_back(k);
				if(Sum > requiredSum)         
					break;
			}	
		}
		if(Sum == requiredSum) {
			++maxCount;
			FOR(m, 0, S.size()) {
				V[S[m]] = true;
			}	
 			if(check(V, n)) {
				return 1;
			}    
		}
	}
	return 0;
}

int main() {
	int T;
	SC(T);
	while(T--) {
		int N, K;
		SC(N); SC(K);
		VLI A(N);
		lint maxSum = 0;
		FOR(i, 0, N) {
			SCC(A[i]);
			maxSum += A[i];
		}
		if((maxSum % K) || N < K) {
			printf("no\n");
			continue;
		}
		lint avearge = maxSum / K;	
		
	    if(storeSubsetIndexes(A, N, avearge, K))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}