#include <cstdio>

using namespace std;

int main () {
	int T, G, I, N, Q;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &G);
		while (G--) {
			scanf ("%d %d %d", &I, &N, &Q);
			if (N % 2 == 0) 
				printf("%d\n", N / 2);
			else {	
				if (I == Q)
					printf("%d\n", N / 2);
				else
					printf("%d\n", N / 2 + 1);
			}
		}
	}
	return 0;
}