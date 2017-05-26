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
typedef vector<vector<pair<int, lint> > > VVPI;
typedef vector<vector<pair<int, pair<lint, lint> > > > VVPPI;

void dijkstra (const vector<vector<pair<int, int> > > &edgeList, int N, int source, VI &distance) {
    set<PI> Q;
    distance[source] = 0;
    Q.insert(make_pair(0, source));

    while (!Q.empty()) {
        PI top = *Q.begin();
        Q.erase(Q.begin());
        int u = top.second;

        for (int j = 0; j < edgeList[u].size (); j++) {
            int v = edgeList[u][j].first;
            int d = edgeList[u][j].second;
            if (distance[v] > distance[u] + d) {
                if (distance[v] != INT_MAX) {
                    Q.erase(Q.find(make_pair (distance[v], v)));
                }
                distance[v] = distance[u] + d;
                Q.insert ((make_pair (distance[v], v)));
            }
        }
    }
}

void solve(int N, VI &from, VI &to, VI &weight, int start, int end, int extra) {
    vector<vector<pair<int, int> > > edgeList(N+1);
    bool connect = false;
    for (int i = 0; i < from.size(); i++) {
        int u = from[i];
        int v = to[i];
        int w = weight[i];
        edgeList[u].push_back(make_pair(v, w));
        edgeList[v].push_back(make_pair(u, w));
        if ((start == u && end == v) || (start == v && end == u))
            connect = true;
    }
    VI fromStart(N+1, INT_MAX);
    dijkstra(edgeList, N, start, fromStart);
    VI fromEnd(N+1, INT_MAX);
    dijkstra(edgeList, N, end, fromEnd);
    int ans = fromStart[end];
    for (int i = 1; i <= N; i++) {
        if (i == start || i == end)
            continue;
        if (fromStart[i] > extra && fromStart[i] != INT_MAX) {
            int temp = extra + fromEnd[i];
            ans = min(ans, temp);
        }
    }
    if ((fromStart[end] == INT_MAX) || (!connect && ans > extra)) {
        ans = extra;
    }
    cout << ans << endl;
}

int main() {
    int N, M;
    cin >> N >> M;
    VI from, to, weight;
    EFOR (i, 1, M) {
        int u, v, w;
        cin >> u >> v >> w;
        from.push_back(u);
        to.push_back(v);
        weight.push_back(w);
    }
    int start, end, extra;
    cin >> start >> end >> extra;
    solve(N, from, to, weight, start, end, extra);
    return 0;
}

















