#include <cstdio>
#include <algorithm>
#define SC(a) scanf("%d", &a)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

using namespace std;

int main() {
	int T, N;
	SC(T);
	while(T--) {
		SC(N);
		int A[N + 1];
		long long int maxSum = 0;
		EFOR(i, 1, N)
			SC(A[i]);
		sort(A, A + N + 1);
		for(int j = N; j >= 1; j -= 2) {
			maxSum += A[j];
		}
		printf("%lld\n", maxSum);	
	}
	return 0;
}