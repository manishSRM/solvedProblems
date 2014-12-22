#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <map>
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
#define MOD 1000000007

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

lint ApowBWithMOD(lint A, int B) {
    lint result = 1;
    while(B) {
        if(B & 1)  
            result = (result * A) % MOD; 
        B >>= 1;
        A = (A * A) % MOD; 
    }
    return result;
}

int giveCountForMultiple(int Num, int M) {
    return (M / Num); 
}

lint countForIndivisualNumber(VI &storeCount, int Num, int M, int N) {
	int countOfMultiples = giveCountForMultiple(Num, M);
	lint total = ApowBWithMOD(countOfMultiples, N);
	FOR(i, 1, countOfMultiples) {
		int nextNumber = Num + (i * Num);
		if((nextNumber) <= M)
			total = (total - storeCount[nextNumber] + MOD) % MOD;	
	}
	return total;
}

void storeTheCountForEachNubmer(VI &storeCount, int N, int M, int L) {
	RFOR(i, M, L) {
		storeCount[i] = countForIndivisualNumber(storeCount, i, M, N);
	}
	return;
}

int main () {
   	int T;
   	SC(T);
   	while(T--) {
   		int N, M, L, R;
   		SC(N); SC(M); SC(L); SC(R);
   		VI storeCount(M + 1);
   		storeTheCountForEachNubmer(storeCount, N, M, L);
   		int ans = 0;
   		EFOR(D, L, R) {
   			ans = (ans + storeCount[D]) % MOD;
   		}
   		printf("%d\n", ans);
   	} 
    return 0;
}
