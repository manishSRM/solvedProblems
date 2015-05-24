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

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

inline int scanme() {
    int n = 0 ;
    char c = getchar_unlocked();
    while(!('0'<=c && c<='9')) {
        c = getchar_unlocked();
    }
    while('0'<=c && c<='9') {
        n = n*10 + c -'0';
        c = getchar_unlocked();
    }
    return n ;
}

int main() {
    int T;
    T = scanme();
    while(T--) {
        int N;
        lint answer = 0;
        lint MIN = INT_MAX;
        N = scanme();
        VI A(N + 1);
        EFOR(i, 1, N) {
            A[i] = scanme();
            answer += A[i];
            if(A[i] < MIN) {
                MIN = A[i];
            }
        }
        answer -= MIN;
        printf("%lld\n", answer * MIN);
    }
    return 0;
}



