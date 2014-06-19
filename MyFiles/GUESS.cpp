#include <cstdio>

using namespace std;

int main () {
	int T;
	long long int N, M;
	scanf ("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf ("%lld %lld", &N, &M);
		if (N == 1 && M == 1) {
			printf("0/1\n");
			continue;
		}
		if (M % 2 == 1 && N % 2 == 1) {
			long long int sampleSpace = M * N;
			long long int oddPairs = M * N / 2;
			printf("%lld/%lld\n", oddPairs, sampleSpace);
		}
		else
			printf("1/2\n");	
	}
	return 0; 
}