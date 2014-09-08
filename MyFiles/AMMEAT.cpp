#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int isBitSet (int mask, int k) {
	return ((mask & (1 << k)) != 0);
}

int minimumRequiredPlates (const vector<long long int> &meatBalls, int N, long long int total) {
	int min = INT_MAX;
	for (int mask = 1; mask < (1 << N); mask++) {
		long long int sum = 0;
		int count = 0; 
		for (int k = 0; k < N; k++) {
			if (sum > total)
				break;
			if (isBitSet (mask, k)) {
				sum += meatBalls[k];
				count++;
				if (sum >= total) 
					break;
			}
		}
		if (sum >= total && count < min)
			min = count;
	}
	if (min == INT_MAX)
		return -1;
	return min;	 
}

int main () {
	int T, N;
	long long int M;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%lld", &N, &M);
		vector <long long int> meatBalls (N);
		for (int i = 0; i < N; i++)
			scanf ("%lld", &meatBalls[i]);
		printf("%d\n", minimumRequiredPlates (meatBalls, N, M));
	}
	return 0;
} 