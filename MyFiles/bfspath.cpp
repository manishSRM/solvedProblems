#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

bool vertex[110];
int minDistance[110];

void initalizeVertex (int size) {
	for (int i = 1; i <= size; i++) {
		vertex[i] = false;
		minDistance[i] = -1;
	}
}

void bfs (const vector<vector <int> > &edgeList) {
	queue<int> Q;
	Q.push (1);
	vertex[1] = true;
	minDistance[1] = 0;
	while (!Q.empty()) {
		int u = Q.front ();
		Q.pop ();
		for (int i = 0; i < edgeList[u].size (); i++) {
			int v = edgeList[u][i];
			if (vertex[v] != true) {
				Q.push (v);
				vertex[v] = true;
				minDistance[v] = minDistance[u] + 1;
 			}
		} 
	}
}

int shortestPath (const vector<vector<int> > &edgeList, int size, int w) {
	initalizeVertex (size);
	bfs (edgeList);
	return minDistance[w]; 
}

int main () 
{
	int T;
	scanf ("%d", &T);
	for (int c = 0; c < T; c++) {
		int N, E;
		scanf ("%d %d", &N, &E);
		vector<vector <int> > edgeList (N + 1);
		for (int k = 0; k < E; k++) {
			int m, n;
			scanf ("%d %d", &m, &n); 
			edgeList[m].push_back (n);
			edgeList[n].push_back (m);
		}
		int secondVertex;
		scanf ("%d", &secondVertex);
		printf("%d\n", shortestPath (edgeList, N, secondVertex));	
	}
	return 0;
}