#include <cstdio>

using namespace std;

int isBitSet (int mask, int k) {
	return ((mask & (1 << k)) != 0);
}

int main () {
	int T, N, M;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d %d", &N, &M);
		int note[N];
		for (int i = 0; i < N; i++)
			scanf ("%d", &note[i]);
		int flag = 0;
		for (int mask = 0; mask < (1 << N); mask++) {
			int maxSum = 0;
			for (int k = 0; k < N; k++) {
				if (isBitSet (mask, k)) {
					maxSum += note[k];		
				}
			}
			if (maxSum == M) { 
				flag = 1;
				break;
			}	
		}
		if (flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}