#include <cstdio>
#include <algorithm>
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
typedef vector<VI> VVI;

int getMinStep(int n, VI &memo) {
    if(!n)
        return 1;
    if(memo[n] != -1)
        return memo[n];
    int r = 1 + getMinStep(n - 1, memo);
    if((n % 2) == 0)
        r = min(r, 1 + getMinStep(n / 2, memo));
    if((n % 3) == 0)
        r = min(r, 1 + getMinStep(n / 3, memo));
    memo[n] = r;
    return r;
}

int getMinStep2(int N) {
    VI dp(N + 1, -1);
    dp[1] = 0;
    for(int i = 2; i <= N; i++) {
        dp[i] = 1 + dp[i - 1];
        if(i % 2 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        if(i % 3 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    return dp[N];
}

int main() {
    int T, N;
    SC(T);
    while(T--) {
        SC(N);
        VI memo(N + 1, -1);
        //int steps1 = getMinStep1(N, memo);
        //printf("%d\n", steps);
        int steps2 = getMinStep2(N);
        printf("%d\n", steps2);
    }
    return 0;
}