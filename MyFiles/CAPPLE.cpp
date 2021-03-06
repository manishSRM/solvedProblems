#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
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
    	int N;
    	SC(N);
    	VI A(N + 1);
    	EFOR(i, 1, N) 
    		SC(A[i]);
    	VI::iterator it = max_element(A.begin(), A.end());
    	VI count((*it) + 1, 0);
    	EFOR(i, 1, N) 
    		++count[A[i]];	
    	int C = 0;
    	EFOR(j, 1, (*it)) {
    		if(count[j])
    			++C;
    	}
    	printf("%d\n", C);
    } 
    return 0;
}
