#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, M, K;
		scanf ("%d %d %d", &N, &M, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) 
				printf("A");
			printf("\n");
		}
	}
	return 0;
}