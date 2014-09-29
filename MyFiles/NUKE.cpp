#include <cstdio>
#include <algorithm>
#define SC(a, b, c) scanf("%d %d %d", &a, &b, &c);

using namespace std;

int main () {
	int N, A, K;
	SC(A, N, K);
	int temp = N + 1;
	printf("%d ", A % temp);
	for(int i = 1; i < K; i++) { 
		printf("%d ", ((A - (A % temp)) / temp) % (N + 1));
		temp *= (N + 1); 
	}
	printf("\n");
	return 0;
}