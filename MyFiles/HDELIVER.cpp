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
void DFS(const VVI &edgeList, VI &visited, int s, int &count) {
    visited[s] = count;
    FOR(j, 0, edgeList[s].size()) {
        int v = edgeList[s][j];
        if(!visited[v]) {
            DFS(edgeList, visited, v, count);
        }
    }
}

int main() {
    int T;
    T = scanme();
    while(T--) {
        int N, M;
        N = scanme();
        M = scanme();
        VVI edgeList(N);
        FOR(i, 0, M) {
            int u, v;
            u = scanme();
            v = scanme();
            edgeList[u].push_back(v);
            edgeList[v].push_back(u);
        }
        int count = 0;
        VI visited(N, 0);
        FOR(j, 0, N) {
            if(!visited[j]) {
                count++;
                DFS(edgeList, visited, j, count);
            }
        }
        int Q;
        Q = scanme();
        while(Q--) {
            int u, v;
            u = scanme();
            v = scanme();
            if(visited[u] == visited[v]) {
                printf("YO\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}












