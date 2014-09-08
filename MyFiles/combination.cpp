#include <cstdio>
#define MOD 4

using namespace std;

typedef long long int lint;

lint ncr[50][50];

lint nCr (int n, int r) {
	if(n == r) 
		return ncr[n][r] = 1;
    if(r == 0) 
    	return ncr[n][r] = 1;
    if(r == 1) 
    	return ncr[n][r] = lint (n);
    if(ncr[n][r])
    	return ncr[n][r];
    ncr[n][r] = (nCr (n - 1, r) + nCr (n - 1, r - 1)) % MOD;
    return ncr[n][r];
}

int main ()
{	
	int n, r;
	scanf ("%d%d", &n, &r);
	r = (r < n - r) ? r : n - r;
	printf("%lld\n", nCr (n, r));
	return 0;
}