#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, K, count = 0, flag = 0;
		scanf ("%d %d", &N, &K);
		vector<int> V(N + 1);
		for (int i = 1; i <= N; i++)
			scanf ("%d", &V[i]);
		for (int j = 1; j <= N; j++) {
			if (V[j] % 2 == 0) 
				count++;
		}
		if (count == N && K == 0) {
			printf("NO\n");
			continue;
		}
		if (count >= K) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}