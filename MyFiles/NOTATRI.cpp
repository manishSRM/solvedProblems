#include <cstdio>
#include <algorithm>
#define MAX 2000

using namespace std;

long long int sticksLength[MAX];

int countWins (long long int sticks[], int size) {
	int count = 0;
	for (int i = 0; i < size - 2; i++) {
		int maxDif = sticks[size - 1] - sticks[i];
		for (int j = i + 1; j < size - 1; j++) {
			if (sticks[j] < maxDif) 
				count++;
		}
	}
	return count;
}

int main () 
{
	while (1) {
		int N; 
		scanf ("%d", &N);
		if (N == 0)
			return 0;
		for (int i = 0; i < N; i++) {
			scanf ("%lld", &sticksLength[i]);
		}
		sort (sticksLength, sticksLength + N);
		printf("%d\n", countWins (sticksLength, N));
	}
	return 0;
}