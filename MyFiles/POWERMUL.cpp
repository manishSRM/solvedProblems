#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

lint ApowBWithMOD(lint A, int B, int MOD, int flag) {
    lint result = 1;
    while(B) {
        if(B & 1) {
        	if(flag) {
            	result *= A;
        		result %= MOD;
        	} else {
        		result *= A;
        	}
        }
        if(flag) {
        	A = (A * A) % MOD; 
        } else {
        	A *= A;
        } 
        B >>= 1; 
    }
    return (flag == 1) ? (result % MOD) : result;
}

int checkPrime(int Num) {
	int flag = 1;
	if(Num == 1) 
		return 0;
	for(int i = 2; i <= Num / i; i++) {
		if(Num % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void initalizeArrayFirst(int N, lint P[], int MOD) {
	EFOR(i, 1, N) { 
		if(i <= 5) {
			P[i] = ApowBWithMOD(i, i, MOD, 0);
		} else {
			P[i] = ApowBWithMOD(i, i, MOD, 1);
		}
	}
	return;
}

void initalizeArraySecond(int N, lint P[], lint F[], int MOD) {
	F[1] = 1, F[2] = 4;
	EFOR(i, 3, N) {
		if(i <= 5) {
			F[i] = P[i] * F[i - 1];
		} else {
			F[i] = (P[i] * F[i - 1]) % MOD;
		}
	}
	return;
}

lint modInverse(lint a, int p) {
	return ApowBWithMOD(a, p - 2, p, 1);
}

void case1(int N, int MOD, int r, lint A[]) {
	printf("%lld\n", (A[N] / (A[r] * A[N - r])) % MOD);
}

void case2(int N, int MOD, int r, lint MI[], lint A[]) {
	lint Fr = MI[r];
	lint Fnr = MI[N - r];
	printf("%lld\n", (((A[N] * Fr) % MOD) * Fnr) % MOD);
}

void initalizeArrayThird(int N, lint F[], lint MI[], int MOD) {
	EFOR(i, 1, N) {
		MI[i] = modInverse(F[i], MOD);
	}
	return;
}

int main() {
	int T;
	SC(T);
	while(T--) {
		int N, MOD, Q, flag = 0;
		SC(N); SC(MOD); SC(Q);
		lint P[100002], F[100002], MI[100002];
		initalizeArrayFirst(N, P, MOD);
		initalizeArraySecond(N, P, F, MOD);
		if(checkPrime(MOD)) {
			flag = 1;
			initalizeArrayThird(N, F, MI, MOD);
		}	
		while(Q--) {
			int r;
			SC(r);
			if(N <= 5) {
				case1(N, MOD, r, F);
			} else if(flag) {
				case2(N, MOD, r, MI, F);
			} else {
				printf("3\n");
			}
		}
	}
	return 0;
}