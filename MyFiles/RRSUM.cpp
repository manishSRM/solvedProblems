#include <cstdio>
#include <cmath>
#define abs(x) ((x) >= 0 ? (x) : -(x))
using namespace std;

int main () {
	long long int N; 
	int M;
	scanf ("%lld %d", &N, &M);
	long long int minSum = N + 2, maxSum = 3 * N, average;
	average = (minSum + maxSum) / 2;
	while (M--) {
		long long int Q;
		scanf ("%lld", &Q);
		if (minSum <= Q && Q <= maxSum) {
			if (Q == average)
				printf("%lld\n", N);
			else {
				long long int final = abs (average - Q);
				printf("%lld\n", N - final);
			}	
		}
		else
			printf("0\n");
	}
	return 0;
}