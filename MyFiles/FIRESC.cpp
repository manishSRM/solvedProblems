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

void DFS_VISIT(const VVI &edgeList, VB &vertex, int s, int &len) {
    vertex[s] = true;
    len++;
    FOR(i, 0, edgeList[s].size()) {
        int v = edgeList[s][i];
        if(vertex[v] != true) {
            DFS_VISIT(edgeList, vertex, v, len);
        }
    }
}

void DFS(const VVI &edgeList, int N) {
    VB vertex(N + 1, false);
    VLI set;
    EFOR(i, 1, N) {
        if(vertex[i] != true) {
            int len = 0;
            DFS_VISIT(edgeList, vertex, i, len);
            set.push_back(len);
        }
    }
    lint result = 1;
    FOR(k, 0, set.size()) {
        result = (result * set[k]) % MOD;
    }
    printf("%lu %lld\n", set.size(), result);
}

int main() {
    int T;
    SC(T);
    while(T--) {
        int N, M;
        SC(N); SC(M);
        VVI edgeList(N + 1);
        EFOR(i, 1, M) {
            int u, v;
            SC(u); SC(v);
            edgeList[u].push_back(v);
            edgeList[v].push_back(u);
        }
        DFS(edgeList, N);
    }
    return 0;
}






