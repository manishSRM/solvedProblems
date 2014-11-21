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
#define SCC(A) scanf("%lld", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

lint findQuantizedFactor(lint K) {
    lint R = 0;
    lint N = 2;
    while(1) {
        if(N * 2 > K) 
            break;
        R += N;
        N *= 2;
    }
    return R + 1;
}

int main () {
    int T;
    SC(T);
    while(T--) {
        lint X;
        lint K;
        SCC(X); SCC(K); 
        if(K == 1) {
            printf("%lf\n", double(X / 2.0));
            continue;
        }
        lint Q = findQuantizedFactor(K);
        K -= Q;
        Q = (Q + 1) * 2;
        double Q2 = double(Q);
        printf("%lf\n", double(((X / Q2) * ((2 * K) - 1));
    } 
    return 0;
}
