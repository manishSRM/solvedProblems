#include <cstdio>
#include <limits.h>

using namespace std;

int main () {
	int N, dif, player, scoreOfFirst = 0, scoreOfSecond = 0, maxDif = INT_MIN, p1, x, y;
	scanf ("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf ("%d %d", &x, &y);
		scoreOfFirst += x; 
		scoreOfSecond += y;
		if(scoreOfFirst > scoreOfSecond) {
			dif = scoreOfFirst - scoreOfSecond;
			player = 1;
		}
		else {
			dif = scoreOfSecond - scoreOfFirst;
			player = 2;
		}
		printf("%d %d %d %d\n", scoreOfFirst, scoreOfSecond, dif, player);
		if(maxDif < dif) {
			maxDif = dif;
			p1 = player;
		}				
	}
	printf("%d %d\n", p1, maxDif);
	return 0;
} 