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
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int main () {
    int T, N, M;
    SC(T);
    while(T--) {
    	SC(N); SC(M);
    	int operations[M + 1];
    	FOR(i, 0, M)
    		SC(operations[i]); 
    	sort(operations, operations + M);
    	int min = operations[0], MAX = operations[M - 1];
    	FOR(j, 0, N) 
    		printf("%d ", max(abs(j - min), abs(j - MAX)));
    	printf("\n");
    }
    return 0;
}
