#include <cstdio>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		long long int N;
		scanf ("%lld", &N);
		if (N % 2 != 0) 
			printf("%lld\n", N - 1);
		else
			printf("%lld\n", N);
	}
	return 0;
}