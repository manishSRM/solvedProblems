#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <sstream>
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
#define MOD 1000000007
#define SC(A) scanf("%d", &A)
#define SCC(A) scanf("%lld", &A)
#define PF(A) printf("%d\n", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

int solve(int N) {
    unsigned int dig[N + 1], first = 0, last = 0, carry, sum = 0;
    dig[0] = dig[1] = 1;
    for(int n = 2; n <= N; n++) {
        carry = 0;
        for(int x = first; x <= last; x++) {
            carry = dig[x]*n + carry;
            dig[x] = carry%10000;
            if(x == first && !(carry%10000))
                first++;
            carry /= 10000;
        }
        if(carry)
            dig[++last] = carry;
    }
    for(int i = first; i <= last; i++)
        sum += dig[i]%10 + (dig[i]/10)%10 + (dig[i]/100)%10 + (dig[i]/1000)%10;
    return sum;
}

int main() {
    int T, N;
    SC(T);
    while (T--) {
        SC(N);
        cout << solve(N) << endl;
    }
    return 0;
}

