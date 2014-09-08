#include <cstdio>

using namespace std;

int main () {
	int T, N, C, x; 
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d", &N, &C);
		int maxSum = 0;
		for (int i = 1; i <= N; i++) {
			scanf ("%d", &x);
			maxSum += x;
		}
		if (maxSum <= C) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}