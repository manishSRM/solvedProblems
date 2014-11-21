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

int checkPrime(int N) {
	int flag = 1;
	if(N == 1)
		return 0;
	for(int i = 2; i <= N / i; i++) {
		if(N % i == 0) {
			flag = 0;
			break;
		}
	}
	return (flag == 1) ? 1 : 0;
}

lint makeNumberFromBinary(const VI &A) {
	int size = A.size(), C = 1;	
	lint Num = 0;
	for(int i = size - 1; i >= 0; i--) {
		if(A[i])
			Num += C;
		C *= 2;
	}
	return Num;
}

int main () {
    int N;
    SC(N);
    VI A;
    while(N--) {
    	int X, maxSum = 0;
    	SC(X);
    	if(X == 0) {
    		A.push_back(0);
    		continue;
    	}
    	while(X) {	
    		maxSum += X % 10;
    		X /= 10;
    	}
    	if(checkPrime(maxSum)) 
    		A.push_back(1);
    	else
    		A.push_back(0);
    }
    printf("%lld\n", makeNumberFromBinary(A));
    return 0;
}
