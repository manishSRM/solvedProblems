#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>

#define FOR(A, B, C) for (int A = B; A < C; A++)
#define EFOR(A, B, C) for (int A = B; A <= C; A++)
#define RFOR(A, B, C) for (int A = B; A >= C; A--) 

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<bool> CHECK;
typedef vector<vector<int> > VVI;

int trackIndex (int &index1, int &index2, VI &index, int size) {
	EFOR(i, 1, size) {
		if (index[index1] == index1)
			break;
		else
			index1 = index[index1];
	}
	EFOR(j, 1, size) {
		if (index[index2] == index2)
			break;
		else
			index2 = index[index2];
	}
	if (index1 == index2)
		return 1;
	else
		return 0;			
}

void solveQueryOne (int x, int y, VVI &dishScore, VI &index, CHECK &visited, int size) {
	int result = trackIndex(x, y, index, size);
	if (result == 1) {
		printf("Invalid query!\n");
		return;
	}
	int bestDish1 = dishScore[x][0], bestDish2 = dishScore[y][0];
	if (bestDish1 > bestDish2) {
		FOR(k, 0, dishScore[y].size()) {
			
			if (dishScore[y][k] > dishScore[x][0])
				swap (dishScore[y][k], dishScore[x][0]);
			
			dishScore[x].push_back(dishScore[y][k]);
		}
		index[y] = x;
		visited[y] = true;	
	}
	if (bestDish2 > bestDish1) {
		FOR(l, 0, dishScore[x].size()) {
			
			if (dishScore[x][l] > dishScore[y][0]) 
				swap(dishScore[x][l], dishScore[y][0]); 
			
			dishScore[y].push_back(dishScore[x][l]);
		}
		index[x] = y;
		visited[y] = true;	
	}
}

void solveQueryTwo (int x, VVI &dishScore, VI &index, CHECK &visited, int size) {
	EFOR(i, 1, size) {
		if (index[x] == x) {
			printf("%d\n", x);
			return;
		}
		else 
			x = index[x];	
	}
}

void solveQuery (int query, VVI &dishScore, VI &index, CHECK &visited, int size) {
	FOR(i, 0, query) {
		int first, x, y;
		scanf ("%d", &first);
		if (first == 0)
			scanf ("%d%d", &x, &y);
		else
			scanf("%d", &x);
		if (first == 0) 
			solveQueryOne (x, y, dishScore, index, visited, size) ;
		else
		    solveQueryTwo (x, dishScore, index, visited, size);		
	}
}

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, query;
		scanf ("%d", &N);
		VVI dishScore(N + 1);
		VI index(N + 1);
		EFOR(i, 1, N)
			index[i] = i;
		CHECK visited(N + 1, false);
		EFOR(j, 1, N) {
			int temp;
			scanf ("%d", &temp);
			dishScore[j].push_back(temp);
		}	
		scanf ("%d", &query);
		solveQuery (query, dishScore, index, visited, N);	
	}
	return 0;
}