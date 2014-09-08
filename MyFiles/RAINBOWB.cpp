#include <cstdio>
#define MOD 1000000007

using namespace std;

typedef long long int lint;

lint ncr[1000000][7];

lint nCr (int n, int r) {
	if(n == r) 
		return ncr[n][r] = 1;
    if(r == 0) 
    	return ncr[n][r] = 1;
    if(r == 1) 
    	return ncr[n][r] = lint (n);
    if(ncr[n][r])
    	return ncr[n][r];
    return ncr[n][r] = (nCr (n - 1, r) + nCr (n - 1, r - 1)) % MOD;
}

lint countPartition (int n, int r) {
    //a1 + a2 + a3 +... + ar = N
	int N = (n + r - 1);
	int K = r - 1;
	K = (K < N - K) ? K : N - K;
	return nCr(N, K);
}

int solve(int M) {
    /*
    2 * (a1 + a2 + a3 + a4 + a5 + a6) + a7 = M
    2 * p + q = M
    */
    int sum = 0;
    for (int p = 0; p <= M; p++) {
        int q = M - (2 * p);
        if (q <= M && q >= 0) 
            sum = (sum + countPartition (p, 6)) % MOD;
    }
    return sum;
}

int main ()
{	
	int N, M;
	scanf ("%d", &N);

	if (N < 13) {
	    printf ("0\n");
	} else {
	    M = N - 13;   
        printf("%d\n", solve (M));
	}
	return 0;
}
