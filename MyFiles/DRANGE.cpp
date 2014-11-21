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

int main () {
    int T;
    SC(T);
    while(T--) {
    	int N, M, first = 1;
    	SC(N); SC(M); 
       	VI A(N + 1), D(N, 1);
        EFOR(i, 1, N) 
            A[i] = i;    
        while(M--) {
    		int w, x, y, z;
    		SC(w); SC(x); SC(y); SC(z);
			if(w == 1) {
                if(x == 1)
                    first += z;
                if(1 <= y && y <= N - 1) 
                    D[y] -= z;
                if(1 <= (x - 1) && (x - 1) <= N - 1)
                    D[x - 1] += z;         
			} else {
                if(x == 1) 
                    first -= z;
                if( 1 <= y && y <= N - 1)
                    D[y] += z;
			    if(1 <= (x - 1) && (x - 1) <= N - 1)
                    D[x - 1] -= z;
            }    		
    	}
        A[1] = first;
        EFOR(j, 2, N) 
            A[j] = D[j - 1] + A[j - 1];
        int MIN = INT_MAX, MAX = INT_MIN;
        EFOR(i, 1, N) {
            if(A[i] > MAX)
                MAX = A[i];
            if(A[i] < MIN)
                MIN = A[i];
        }
        printf("%d\n", MAX - MIN);
    }
    return 0;
}
