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

#define MAX 1000002
#define MOD 10000009

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
typedef map<int,int> MP;

int main() {
    int T;
    SC(T);
    while(T--) {
        char str[MAX];
        scanf("%s", str);
        int len = strlen(str);
        int N = len;
        if(!(len % 2)) {
            len = (len / 2) - 1;
        } else {
            len /= 2;
        }
        lint answer = 1;
        EFOR(i, 0, len) {
            if(str[i] != str[N - i - 1] && str[i] != '?' && str[N - i - 1] != '?') {
                answer *= 0;
                break;
            } else if(str[i] == str[N - i - 1] && str[i] == '?') {
                answer = (answer * 26) % MOD;
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}









