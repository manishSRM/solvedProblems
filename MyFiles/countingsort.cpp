#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
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

void countingSort(const VI &A, VI &B, int k, int N) {
	VI C(k + 1, 0);
    EFOR(j, 1, N) {
    	++C[A[j]];
    }	
    EFOR(l, 1, k) {
    	C[l] += C[l - 1];
    }
   	RFOR(k, N, 1) {
   		B[C[A[k]]] = A[k];
   		C[A[k]]--;
   	}
}

int main () {
	int N;
	SC(N);
    VI A(N + 1), resultVector(N + 1);
    EFOR(i, 1, N) {
    	SC(A[i]);
    }
    VI::iterator it = max_element(A.begin(), A.end());
   	countingSort(A, resultVector, (*it), N);
   	EFOR(i, 1, N) 
   		printf("%d ", resultVector[i]);
   	printf("\n");	 
    return 0;
}
