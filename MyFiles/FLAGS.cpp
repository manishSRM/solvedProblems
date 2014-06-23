#include <cstdio>

using namespace std;

int main () 
{
	int T;
	scanf ("%d", &T);
	while(T--) {
		int N;
		scanf ("%d", &N);
		long long int s1 = N * (N - 1) * (N - 1);
		long long int s2 = N * (N - 1) * (N - 1);
		long long int s3 = N * (N - 1) * (N - 2);
		long long int s4 = N * (N - 1) * (N - 2) * ( N-2);
		long long int s5 = N * (N - 1) * (N - 2) * ( N-2);
 		printf ("%lld\n", s1 + s2 + s3 + s4 + s5);
	}
	return 0;
}