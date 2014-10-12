#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int grid[102][102];

int maximumPossibleIndexInRow(int row, int j, int M) {
	EFOR(k, j + 1, M) {
		if(grid[row][k] == -1 || grid[row][k] == 1)
			return k - 1;
	}
	return M;
}	

int maximumPossibleIndexInColumn(int i, int column, int N) {
	EFOR(k, i + 1, N) {
		if(grid[k][column] == -1 || grid[k][column] == 1)
			return k - 1;
	}
	return N;
}

int main () {
    int N, M, K, i, j;
    SC(N); SC(M); SC(K);
   	EFOR(i, 1, N) {
   		EFOR(j, 1, M)
   		grid[i][j] = 0;
   	}
   	while(K--) {
   		SC(i); SC(j);
   		grid[i][j] = -1;
   	}
   	VPI storeIndex;
   	int direction[N + 1][M + 1], steps = 0;
   	EFOR(p, 1, N) {
   		EFOR(q, 1, M)
   			direction[p][q] = 0;
   	}
   	EFOR(i, 1, N) {
   		EFOR(j, 1, M) {
   			if(grid[i][j] == 0) {
   				int rowIndex = maximumPossibleIndexInRow(i, j, M);
   				int columnIndex = maximumPossibleIndexInColumn(i, j, N);
   				if((rowIndex - j) > (columnIndex - i)) {
   					storeIndex.push_back(make_pair(i, j));
   					EFOR(l, j, rowIndex)
   						grid[i][l] = 1;
   					steps++;
   				}
   				else {
   					storeIndex.push_back(make_pair(i, j));
   					direction[i][j] = 1;
   					EFOR(m, i, columnIndex)
   						grid[m][j] = 1;
   					steps++;
   				}
   			}
   		}
   	}
   	printf("%d\n", steps); 
   	FOR(a, 0, storeIndex.size()) {
   		int J = storeIndex[a].second;
   		int I = storeIndex[a].first;
   		printf("%d %d %d\n", I, J, direction[I][J]);
   	}
    return 0;
}
