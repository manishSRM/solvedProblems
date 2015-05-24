#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <deque>
#include <bitset>
#include <map>
#include <assert.h>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)
#define MOD 1000000007

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

int main() {
    int T;
    SC(T);
    while(T--) {
        vector<lint> N(3);
        FOR(i, 0, 3) {
            scanf("%lld", &N[i]);
        }
        sort(N.begin(), N.end());
        lint ans = 1;
        FOR(i, 0, 3) {
            lint num = (N[i] - i + MOD) % MOD;
            ans = (ans * num) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
