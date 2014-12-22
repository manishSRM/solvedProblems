#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <deque>
#include <map>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

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
typedef map<int,int> MP;

int main () {
    int T;
    SC(T);
    while(T--) {
    	int N;
    	SC(N);
    	FOR(i, 0, N) {
    		int x, y;
    		SC(x); SC(y);
    	}
    	int result = 0;
    	EFOR(j, 1, N) {
    		result ^= j;
    	}
    	printf("%d\n", result);
    } 
    return 0;
}
