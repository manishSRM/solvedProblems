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

void countReverse (const VVII &edgeLsit, int N, int source) {
	VI distance (N + 1, MAXINT);
	set<II> Q;
	distance[source] = 0;
	Q.insert (make_pair(0, source));

	while (!Q.empty ()) {
		II top = *Q.begin();
		Q.erase (Q.begin());
		int u = top.second;

		for (int j = 0; j < edgeLsit[u].size (); j++) {
			int v = edgeLsit[u][j].first;
			int d = edgeLsit[u][j].second;
			if (distance[v] > distance[u] + d) {
				if (distance[v] != MAXINT) {
					Q.erase(Q.find(make_pair (distance[v], v)));
				}
				distance[v] = distance[u] + d;
				Q.insert (make_pair(distance[v], v));	
			}
		} 
	}
	if (distance[N] == MAXINT) {
		printf("-1\n");
		return;
	}
	printf("%d\n", distance[N]);
}

int main () {
	int N, M;
	scanf ("%d %d", &N, &M);
	VVII edgeLsit (N + 1);
	while (M--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		edgeLsit[x].push_back (make_pair(y, 0));
		if (x != y)
			edgeLsit[y].push_back (make_pair(x, 1));
		else
			edgeLsit[y].push_back (make_pair(x, 0));
	}
	countReverse (edgeLsit, N, 1);
	return 0;
}