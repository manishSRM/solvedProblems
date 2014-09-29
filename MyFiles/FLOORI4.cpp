#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#define lint long long int
#define SC(n) scanf("%d", &n);
#define SCL(N) scanf("%lld", &N);
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

using namespace std;

typedef pair<lint,lint> PL;
int MOD;

PL floorNumRange (lint N, int num)  {
	lint A = (N / (num + 1)) + 1;
	lint B = N / num;
	return make_pair(A, B);

}

lint sum1toNPower4 (lint A) {
	//n(1 + n)(1 + 2n)(-1 + 3n + 3n^2) / 30
	int MOD1 = 30 * MOD;
	A %= MOD1;
	lint sum = (A * (1 + A)) % MOD1;
	lint y = sum = (sum * ((2 * A) + 1)) % MOD1;
	sum = (sum * (3 * A)) % MOD1;
	sum = (sum * (1 + A)) % MOD1;
	sum = (sum - y + MOD1) % MOD1;
	return (sum / 30) % MOD1;
}

lint sumAtoBPower4 (lint A, lint B) {	
	lint S1 = sum1toNPower4 (B);
	lint S2 = sum1toNPower4 (A - 1);
	return ((S1 - S2 + MOD) % MOD); 
}

lint power4ofN (lint i) {
	i %= MOD;
	lint y = (i * i) % MOD;
	y = (y * y) % MOD;
	return y;	
}

lint firstHalfSum (lint N, int l) {
	lint sum = 0;
	EFOR(i, 1, l) {
		lint y = N / i;
		sum = (sum + (power4ofN (i) * y) % MOD) % MOD;
	}
	return sum;	
}

lint secondHalfSum (lint N, int l) {	
	lint sum = 0;
	EFOR(j, 1, l) {
		PL range = floorNumRange(N, j);
		if (range.second <= l) continue;
		range.first = max (range.first, (long long)(l+1));
		sum = (sum + (sumAtoBPower4(range.first, range.second) * j) % MOD) % MOD;
	}
	return sum;
}

int main()
{	
	int T; lint N;
	SC(T);
	while(T--) {
		 SCL(N); SC(MOD);
		int maxSum = 0, squareRootN = sqrt(N);
		maxSum = (maxSum + firstHalfSum (N, squareRootN)) % MOD;
		maxSum = (maxSum + secondHalfSum (N, squareRootN)) % MOD;
		printf("%d\n", maxSum);
	}
	return 0;
} 