#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
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

vector<bool> vertices(100, false);
VI path;

void DFS_VISIT(const VVI &edgeList, VPI &V, int &T, int &u) {
	T += 1;
	V[u].first = T;
	vertices[u] = true;
	FOR(j, 0, edgeList[u].size()) {
		int v = edgeList[u][j];
		if(vertices[v] == false) {
			path.push_back(v);
			DFS_VISIT(edgeList, V, T, v);
		}
	}
	T += 1;
	V[u].second = T;
	path.push_back(u);
}

void DFS(const VVI &edgeList, VPI &timeVector, int N) {
	int Time = 0;
	EFOR(i, 1, N) {
		if(vertices[i] == false) {
			path.push_back(i);
			DFS_VISIT(edgeList, timeVector, Time, i);
		}
	}
}

void showPathOfGraph() {
	FOR(i, 0, path.size()) {
   		printf("%d ", path[i]);
   		if(i != path.size() - 1)
   			printf("-> ");
   	}
   	printf("\n");
}

int main () {
   	int N, E;
   	SC(N); SC(E);
   	VVI edgeList(N + 1);
   	VPI timeVector(N + 1);
   	EFOR(i, 1, E) {
   		int x, y;
   		SC(x); SC(y);
   		edgeList[x].push_back(y);
   	}
   	DFS(edgeList, timeVector, N);
   	showPathOfGraph();
    return 0;
}
