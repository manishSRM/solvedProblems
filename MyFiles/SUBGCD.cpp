#include <cstdio>
#include <limits.h>
#include <algorithm>
#define SC(n) scanf("%d", &n);

using namespace std;

int gcd(int a, int b)
{	
	if (b)
	    return gcd(b, a % b);
	return a;
}

int main() 
{
	int T, N;
	SC(T);
	while(T--) {
		SC(N);
		int A[N + 1];
		for(int i = 1; i <= N; i++)  
			SC(A[i]);
		
		int flag = 0, GCD = A[1];
		for(int j = 2; j <= N; j++) 
			GCD = gcd(GCD, A[j]);
		if (GCD == 1) 
			printf("%d\n", N);
		else
			printf("-1\n");		
	}
	return 0;
}