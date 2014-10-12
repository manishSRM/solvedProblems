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
#define PF(A) scanf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int main () {
	int T, N, D, O;
	SC(T);
	while(T--) {
		SC(N);
		lint maxSum = 0;
		EFOR(i, 1, N) {
			SC(D); SC(O);
			int n = O / D;
			int A = O + (n - 1) * (-1 * D);
			maxSum += (n * (O + A)) / 2;
			maxSum += O % D;
		}
		if(maxSum % 2 != 0) 
			printf("YES\n");
		else
		 	printf("NO\n");	
	} 
    return 0;
}
