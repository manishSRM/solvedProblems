#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <deque>
#include <map>
#include <assert.h>
#include <iostream>
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
typedef vector<VPI> VVPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;
typedef pair<int, pair<int, int> > PP;
typedef vector<PP> VPP;

void checkSetContent(const set <PI> &Q) {
	set<PI> :: iterator it = Q.begin();
	for(; it != Q.end(); it++) {
		printf("%d %d\n", it -> second, it -> first);
	}
	printf("\n");
	return;
}

void Prims(const VVPI &edgeList, VPI &result, int N, int source) {
	VB checkVertex(N + 1, false);
	VI distance(N + 1, INT_MAX), parent(N + 1);
	distance[source] = 0;
	parent[source] = source;
	set<PI> Q;
	Q.insert(make_pair(distance[source], source));
	while(!Q.empty()) {
		PI top = *Q.begin();
		Q.erase(Q.begin());
		int u = top.second;
		checkVertex[u] = true;
		if(parent[u] != u) {
			result.push_back(make_pair(parent[u], u));
		}
		FOR(i, 0, edgeList[u].size()) {
	 		int v = edgeList[u][i].first;
			int w = edgeList[u][i].second;
	 		if(w < distance[v] && checkVertex[v] != true) {
	 			if(distance[v] != INT_MAX) {
	 				Q.erase(Q.find(make_pair(distance[v], v)));
	 			}
	 			distance[v] = w;
	 			parent[v] = u;
	 			Q.insert(make_pair(distance[v], v));
	 		}
		}
	}	
}	

int main () {
	int N, E;
	SC(N); SC(E);
	VVPI edgeList(N + 1);
	EFOR(i, 1, E) {
		int u, v, w;
		SC(u); SC(v); SC(w);
		edgeList[u].push_back(make_pair(v, w));
		edgeList[v].push_back(make_pair(u, w));
	}
	VPI result;
	Prims(edgeList, result, N, 1);
	FOR(i, 0, result.size()) {
		printf("%d %d\n", result[i].first, result[i].second);
	} 
    return 0;
}
