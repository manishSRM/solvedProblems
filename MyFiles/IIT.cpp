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
#include <limits.h>
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



int main() {
	int T, N;
	SC(T);
	while(T--) {
		int flag = 0, d = INT_MIN, k;
		SC(N);
		while (N) {
			k = d;
			d = N % 10;
			N = N / 10;
			if (k == d && k==1) {
				flag = 1;
				break;
			}
			else if (d > 1 || k > d ) {
				flag = 1;
				break;
			}

		}
		if (flag) 
			printf("YES");
		else
			printf("NO");
			printf("\n");
		}		 
	return 0;
}