#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

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

lint solveQueryForSecond (int x, int y, const VPI &intervals, const VI &A) {
	lint maxSum = 0;
	EFOR(i, x, y) {
		int m = intervals[i].first, n = intervals[i].second;
		EFOR(j, m, n) {
			maxSum += A[j];
		}
	}
	return maxSum;
}

int main () {
    int N, Q;
    SC(N);
    VI Array(N + 1);
    EFOR(k, 1, N)
    	SC(Array[k]);
    VPI intervals(N + 1);
    EFOR(i, 1, N) {
    	int L, R;
    	SC(L); SC(R);
		intervals[i] = (make_pair(L, R));	
    }
    SC(Q);
   	while(Q--) {
   		int query, x, y;
   		SC(query); SC(x); SC(y);
   		if(query == 1) {
 			Array[x] = y;
   		} else {
   			printf("%lld\n", solveQueryForSecond(x, y, intervals, Array));
   		}
   	}
    return 0;
}
