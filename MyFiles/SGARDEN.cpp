#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define MAX 100000

using namespace std;

typedef pair <int, int> II;
typedef vector <int> VI;
typedef vector <II> VII;
typedef vector <bool> CHECK;
typedef unsigned long long int ulint;

void lcm (int num, VI &primePowerCount) {
	if (num == 2 || num == 3) {
		if (primePowerCount[num] == 0)
			primePowerCount[num] = 1;
	}
	for (int i = 2; i <= num / i; i++) {
		int count = 0;
		if (num % i == 0) {
			do {
				count++;
			    num /= i;
			} while (num % i == 0);
		}
		if (count != 0 && primePowerCount[i] < count)
			primePowerCount[i] = count;
	}
	if (num > 1 && primePowerCount[num] == 0)
		primePowerCount[num] = 1;	
}

void computeNumberOfwhistle (const VI &Cycles) {
	VI primePowerCount (MAX + 1, 0);
	FOR(i, 0, Cycles.size())  
		lcm (Cycles[i], primePowerCount);
		
	long long int LCM = 1;
	FOR(j, 2, MAX) {
		if (primePowerCount[j] != 0) {
			for (int k = primePowerCount[j]; k >= 1; k--) {
				LCM *= j;
				LCM %= 1000000007; 
			}
		}
	}
	printf("%lld\n", LCM);	
}

void countMaxCycle (const VI &v, VI &CYCLES, CHECK &C, int size) {
	FOR(i, 1, size) {
		if (C[i] == true)
			continue;
		int count = 1;
		C[i] = true;
		for (int j = v[i]; j <= size;) {
			if (C[j] == true)
				break;
			count++;
			C[j] = true;
			j = v[j];
		}
		CYCLES.push_back (count);
	}
}

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int size, temp;
		scanf ("%d", &size);
		VI rule(size + 1), cycles;
		CHECK C(size + 1, false);
		EFOR(i, 1, size) 
			scanf ("%d", &rule[i]);
		
		countMaxCycle (rule, cycles, C, size);
		computeNumberOfwhistle (cycles);
	}
 	return 0;
}	