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
typedef map<int,int> MP;

int max(int a, int b) {
    return (a>b) ? a : b;
}

int main() {
    int N;
    lint X, negativeSum = 0, l;
    SC(N);
    VLI A(N), V;
    FOR(i, 0, N) {
        SCC(A[i]);
        if(A[i] < 0)
            V.push_back(-A[i]);
    }
    sort(V.begin(), V.end());
    SCC(X);
    if(V.size() <= X) {
        l = 0;
    } else {
        l = V[V.size() - X - 1];
    }
    negativeSum = l * X;
    for(int i = max(V.size() - X, 0); i < V.size(); i++)
        negativeSum+= V[i] - l;
    printf("%lld\n", negativeSum);
    return 0;
}


