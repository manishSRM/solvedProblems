#include <cstdio>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <utility>
#define SC(a) scanf("%d", &a)
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)

using namespace std;

struct Count {
	int countPrime[4];
};

void divideIfPossible(Count &temp, int num) {
	int b[2] = {2, 3};
	for(int i = 0; i < 2; i++) {
		int counter = 0;
		if (num % b[i] == 0) {
			do {
				num /= b[i];
				counter++;
			} while(num % b[i] == 0);
		}
		temp.countPrime[b[i]] = counter;
	}	
}

void countTwoThree (int A[], int N) {
	Count C1[N + 1];
	EFOR(i, 1, N) 
		divideIfPossible(C1[i], A[i]);
	int maxForTwo = INT_MIN, maxForThree = INT_MIN;
	EFOR(j, 1, N) {
		if(maxForTwo < C1[j].countPrime[2])
			maxForTwo = C1[j].countPrime[2];
		if(maxForThree < C1[j].countPrime[3])
			maxForThree = C1[j].countPrime[3];
	}
	printf("%d\n", maxForThree + maxForTwo);	
}

int main() {
	int T, N;
	SC(T);
	while(T--) {
		SC(N);
		int A[N + 1];
		EFOR(i, 1, N)
			SC(A[i]);
		countTwoThree(A, N);			
	}
	return 0;
}