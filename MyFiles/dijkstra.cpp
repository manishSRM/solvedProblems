#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>

#define FOR(A, B, C) for (int A = B; A < B; A++)
#define EFOR(A,B, C) for (int A = B; A <= B; A++)
#define RFOR(A, B, C) for (int A = B; A >= C; A--)

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VII> VVII;

const int MAXINT = 1000000000;

int dijkstra (const VVII &edgeList, int N, int source) {
	VI distance(N + 1, MAXINT);
	set<II> Q;
	distance[source] = 0;
	Q.insert(make_pair(0, source));

	while (!Q.empty()) {
		II top = *Q.begin();
		Q.erase(Q.begin());
		int u = top.second;

		for (int j = 0; j < edgeList[u].size (); j++) {
			int v = edgeList[u][j].first;
			int d = edgeList[u][j].second;
			if (distance[v] > distance[u] + d) {
				if (distance[v] != MAXINT) {
					Q.erase(Q.find(make_pair (distance[v], v)));
				}
				distance[v] = distance[u] + d;
				Q.insert ((make_pair (distance[v], v)));
			}
		}
	}
	for (int i = 1; i <= 5; i++)
		printf("%d ", distance[i]);
	printf("\n");
}

int main () {
    int N, M, T;
    scanf ("%d %d %d", &N, &M, &T);
    VVII edgeList(N + 1);
    while (M--) {
        int x, y, z;
        scanf ("%d %d %d", &x, &y, &z);
        edgeList[x].push_back(make_pair(y, z));
        edgeList[y].push_back(make_pair(x, z));
    }
    dijkstra (edgeList, N, 4);
    return 0;
}
