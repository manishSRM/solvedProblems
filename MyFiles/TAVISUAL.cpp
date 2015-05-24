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

void solveQuery(int L, int R, int &C) {
    if(C < L || C > R) {
        return;
    }
    int mid = (L + R) / 2;
    if(C <= mid) {
        C = R - (C - L);
    } else {
        int dif =
        C = L + (R - C);
    }
}

int main() {
    int T, C;
    SC(T);
    while(T--) {
        int N, Q;
        SC(N); SC(C); SC(Q);
        while(Q--) {
            int L, R;
            SC(L); SC(R);
            solveQuery(L, R, C);
        }
        printf("%d\n", C);
    }
    return 0;
}



