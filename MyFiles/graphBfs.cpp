#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

bool vertices[110];

void initalizeVertex (int size) {
    for (int i = 1; i <= size; i++) 
        vertices[i] = false;
}

void bfs (const vector<vector<int> > &edgeList) {
    queue<int> Q;
    Q.push (1);
    vertices[1] = true;
    while (!Q.empty()) {
        int u = Q.front ();
        Q.pop ();
        for (int j = 0; j < edgeList[u].size (); j++) {
            int v = edgeList[u][j];
            if (vertices[v] != true) {
                Q.push (v);
                vertices[v] = true;
            }
        }
    }
}

int checkConnected (int size, const vector<vector<int> > &edgeList) {
    initalizeVertex (size);
    bfs (edgeList);
    for (int i = 1; i <= size; i++) {
        if (vertices[i] == false)
            return 0;
    }
    return 1;
}

int main () {
    int T, N, E, m, n;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf ("%d %d", &N, &E);
        vector<vector<int> > edgeList(N + 1);
        for (int j = 0; j < E; j++) {
            scanf ("%d %d", &m, &n);
            edgeList[m].push_back (n);
            edgeList[n].push_back (m);
        }
        printf("%d\n", checkConnected (N, edgeList));
    }    
    return 0;
}
