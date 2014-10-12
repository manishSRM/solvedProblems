#include <cstdio>
#include <algorithm>
#include <limits.h>
#define SC(a) scanf("%d", &a);
#define PF(a) printf("%d\n", a);
#define EFOR(A, B, C) for(int A = B; A <= C; A++)

using namespace std;

int main() {
	int T, N, M;
	SC(T);
	while(T--) {
		SC(N); SC(M);
		int A[N + 1], maxValue = INT_MIN, sum = 0; 
		EFOR(i, 1, N) {
			SC(A[i]);
			if(maxValue < A[i])
				maxValue = A[i];
		}
		EFOR(j, 1, N) 
			sum += maxValue - A[j];
		if(sum == M) {
			printf("Yes\n");
			continue;
		}
		if(sum < M) {
			if((M - sum) % N == 0) 
				printf("Yes\n");
			else
				printf("No\n");
		}
		if(sum > M) 
			printf("No\n");		
	}
	return 0;
}