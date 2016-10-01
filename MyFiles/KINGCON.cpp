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

void DFS(const VVI &edgeList, VB &isVisited, VB &isLeaf, int s) {
    isVisited[s] = true;
    FOR(i, 0, edgeList[s].size()) {
        int v = edgeList[s][i];
        if(!isVisited[v]) {
            DFS(edgeList, isVisited, isLeaf, v);
            int x = edgeList[v][0];
            if(edgeList[v].size() == 1 && edgeList[x].size() != 1) {
                isLeaf[v] = true;
            }
        }
    }
}

void solve(const VVI &edgeList, int N, int K) {
    VB isVisited(N, false);
    VB isLeaf(N, false);
    if(edgeList[0].size() == 1) {
        isLeaf[0] = true;
    }
    DFS(edgeList, isVisited, isLeaf, 0);
    int c = 0;
    FOR(i, 0, N) {
        if(!isLeaf[i])
            c++;
    }
    printf("%d\n", c * K);
}

int main() {
    int T;
    SC(T);
    while(T--) {
        int N, M, K;
        SC(N); SC(M); SC(K);
        VVI edgeList(N);
        while(M--) {
            int u, v;
            SC(u); SC(v);
            edgeList[u].push_back(v);
            edgeList[v].push_back(u);
        }
        if(N == 2) {
            printf("%d\n", K);
            continue;
        }
        solve(edgeList, N, K);
    }
    return 0;
}




