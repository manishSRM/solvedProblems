#include <cstdio>

using namespace std;

int main () {
	int T;
	long long int N, K;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld", &N);
		scanf ("%lld", &K);
		if (N == 0) {
			printf("0 0\n");
			continue;
		}
		if (K == 0) {
			printf("0 %lld\n", N);
			continue;
		}
		printf("%lld %lld\n", N / K, N % K);
	}
	return 0;
}