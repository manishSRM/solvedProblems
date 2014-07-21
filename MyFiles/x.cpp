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

int find (VI &parent, int i) {
	if (parent[i] == i)
		return i;
	else {
		int result = find (parent, parent[i]);
		parent[i] = result;
		return result;	
	}
}

void Union (VI &parent, int x, int y) {
	parent[y] = x;
}

void solveQueryOne (VI &dishScore, VI &parent, int x, int y) {
	int X = find (parent, x);
	int Y = find (parent, y);
	if(X == Y) {
		printf("Invalid query!\n");
		return;
	}
	int bestDish1 = dishScore[X], bestDish2 = dishScore[Y];
	if (bestDish1 > bestDish2) 
		Union (parent, X, Y);
	if (bestDish2 > bestDish1)
		Union (parent, Y, X);
}

void solveQueryTwo (VI &dishScore, VI &parent, int x) {
	int X = find (parent, x);
	printf("%d\n", X);
}

void solveQuery (VI &dishScore, VI &parent, int query) {
	FOR(i, 0, query) {
		int first, x, y;
		scanf ("%d", &first);
		if (first == 0)
			scanf ("%d %d", &x, &y);
		else
			scanf("%d", &x);
		printf("%d %d\n", first, x);
		//if (!first)
		//	solveQueryOne (dishScore, parent, x, y);
		//else
		//	solveQueryTwo (dishScore, parent, x);
	}
}

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, query;
		scanf ("%d", &N);
		VI dishScore (N + 1);
		VI parent(N + 1);
		EFOR(i, 1, N)
			parent[i] = i;
		FOR(j, 1, N) 
			scanf ("%d", &dishScore[j]);
		scanf ("%d", &query);
		solveQuery (dishScore, parent, query);	
	}
	return 0;
}