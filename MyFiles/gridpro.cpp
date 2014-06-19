#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int grid[100][100];
bool visited[100][100];

int xOff[4] = {0, 0, 1, -1};
int yOff[4] = {1, -1, 0, 0}; 

void initalizeCell (int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)  
            visited[i][j] = false;
    }
}

int bfs (int M, int N) {
    queue<pair<int, int> > Q;
    Q.push (ii (0, 0));
    visited[0][0] = true;
    int distance = 0;
    while (!Q.empty()) {
        ii kk = Q.front();
        Q.pop();
        int u1 = kk.first;
        int u2 = kk.second;
        int xTemp = 
       // trace2(u1, u2)
        for (int k = 0; k < 4; k++) {
            int x1 = u1 + xOff[k];
            int y1 = u2 + yOff[k];
            if ((0 <= x1) && (x1 < M) && (0 <= y1) && (y1 < N) && (grid[x1][y1] == 0) && (visited[x1][y1] != true)) {
               visited[x1][y1] = true;
               Q.push (ii (x1, y1));
            }
        }
    }
    return distance;
}

int checkConnected (int M, int N) {
    initalizeCell (M, N);
    int distance = bfs (M, N);
  //  trace1(grid[M - 1][N - 1])
    if (visited[M - 1][N - 1] == true)
        return distance;
    else
        return 0;
    
}

int main () 
{
    int T;
    scanf ("%d", &T);
    for (int k = 0; k < T; k++) {
        int M, N;
        scanf ("%d %d", &M, &N);
        //trace2(M, N)
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) 
                scanf ("%d", &grid[i][j]);
        }
        printf ("%d\n", checkConnected (M, N));
    }
    return 0;
}