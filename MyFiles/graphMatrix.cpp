#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int M[110][110];
bool vertices[110];
queue<int>Q;

void initalizeVertices (int size) {
    for(int i = 1; i <= size; i++)
        vertices[i] = false;
}

void initalizeMatrix (int size) {
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= size; j++)
            M[i][j] = 0;
    }
}

void storeInQueue (int size) {
    Q.push (1);
    vertices[1] = true; 
    while (!Q.empty()) {
        int u = Q.front ();
        Q.pop ();      
        for (int j = 1; j <= size; j++) {
            if (M[u][j] != 0 && vertices[j] != true) {
                Q.push (j);
                vertices[j] = true;
            }
        }
    }
} 

int checkConect (int size) {
    for (int i = 1; i <= size; i++) {
        if (vertices[i] == false)
            return 0;
    }
    return 1;
}

int main () {
    int T, N, E, i, j;
    scanf("%d", &T);
    for (int c = 0; c < T; c++) {
        scanf("%d %d", &N, &E);
        initalizeMatrix (N);
        initalizeVertices (N);
        for (int d = 0; d < E; d++) {
            scanf("%d %d", &i, &j);
            M[i][j] = M[j][i] = 1;    
        }
        //printf("%d\n", M[1][1]);
        storeInQueue (N);
        printf("%d\n", checkConect (N)); 
    }
    return 0;
}


