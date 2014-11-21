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

int main () {
    int N, stone, x, flag = 0;
    SC(N); SC(stone);
    FOR(i, 0, N) {
    	FOR(j, 0 ,N) {
    		SC(x);
    		if(x == stone) 
    			flag = 1;
    	}	
    }
   	if(flag)
   		printf("YES\n");
   	else
   		printf("NO\n");	 
    return 0;
}
