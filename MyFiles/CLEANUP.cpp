#include <cstdio>
#include <vector>

using namespace std;

int main () {
	int T, N, M, index;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d", &N, &M);
		vector <bool> visited( N + 1, false);
		for (int i = 0; i < M; i++) {
			scanf ("%d", &index);
			visited[index] = true;
		}
		int flag = 0;
		for (int j = 1; j <= N; j++) {
			if (visited[j] == false && flag == 0) {
				flag = 1;
				visited[j] = true;
				printf("%d ", j);
			}
			if (visited[j] == false && flag == 1)
				flag = 0;
		}
		printf("\n");
		for (int k = 1; k <= N; k++) {
			if (visited[k] == false)
				printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}