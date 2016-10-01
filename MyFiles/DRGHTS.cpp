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

void do_dfs(const VVI &edgeList, VB &visited, const VI &label, VI &vertexCount, int v) {
    visited[v] = true;
    vertexCount[v] = label[v];

    FOR(j, 0, edgeList[v].size()) {
        int x = edgeList[v][j];
        if (!visited[x]) {
            do_dfs(edgeList, visited, label, vertexCount, x);
            vertexCount[v] += vertexCount[x];
        }
    }
}

void solve(const VVI &edgeList, const VI &label, VI &vertexCount, lint N) {
    VB visited(N + 1, false);
    EFOR(i, 1, N) {
        if (label[i]) {
            do_dfs(edgeList, visited, label, vertexCount, i);
            break;
        }
    }
}

int main() {
    int N, M;
    SC(N); SC(M);
    VI label(N + 1);
    lint ans1 = 0;
    int ans2 = 0;
    EFOR(i, 1, N) {
        int x;
        SC(x);
        if(x) {
            ans1 += 1;
        }
        label[i] = x;
    }
    VVI  edgeList(N + 1);
    EFOR(j, 1, M) {
        int u, v;
        SC(u); SC(v);
        edgeList[u].push_back(v);
        edgeList[v].push_back(u);
    }
    VI vertexCount(N + 1, 0);
    solve(edgeList, label, vertexCount, N);
    EFOR(k, 1, N) {
        if(vertexCount[k]) {
            ans2++;
        }
    }
    if(ans1 == 1) {
        ans2 = 0;
    }
    EFOR(l, 1, N) {
        //PF(vertexCount[l]);
    }
    printf("%lld %d\n", (ans1 * (ans1 - 1)) / 2, ans2);
    return 0;
}
