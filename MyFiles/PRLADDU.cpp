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
#include <cmath>
#include <iostream>
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SC(A) scanf("%d", &A)
#define PF(A) scanf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int main () {
    int T, N;
    SC(T);
    while(T--) {
    	SC(N);
    	VI D(N + 1); 
    	queue<int> storeIndex;
    	lint minimumUnitGrass = 0;
    	EFOR(i, 1, N) {
    		SC(D[i]);
    		if(D[i] < 0) 
    			storeIndex.push(i);
    	}
    	for(int j = 1; j <= N;) {
    		if(D[j] > 0) {
    			int dinosaurIndex = storeIndex.front();
    			if(abs(D[dinosaurIndex]) < D[j]) {
    				minimumUnitGrass += abs(D[dinosaurIndex]) * abs(j - dinosaurIndex);
    				D[j] -= abs(D[dinosaurIndex]);
    				storeIndex.pop();
  					//printf(" < %d %d\n", D[j], abs(j - dinosaurIndex));		
    			} else if(abs(D[dinosaurIndex]) == D[j]) {
                    minimumUnitGrass += D[j] * abs(j - dinosaurIndex);
                    storeIndex.pop();
                    j++;
                    //printf(" == %lld\n", minimumUnitGrass);   
                } else if(abs(D[dinosaurIndex]) > D[j]) {
                    minimumUnitGrass += D[j] * abs(j - dinosaurIndex);
                    D[dinosaurIndex] = D[j] - abs(D[dinosaurIndex]);
                    j++;
                    //printf(" > %d\n", D[dinosaurIndex]);
                }
    		}
    		else 
    			j++;
    		//printf("%lld\n", minimumUnitGrass);
    	}
    	printf("%lld\n", minimumUnitGrass);
    }
    return 0;
}
