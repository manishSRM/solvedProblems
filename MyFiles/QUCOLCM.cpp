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

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

int cmp(const PI &A, const PI &B) {
	if(A.second < B.second)
		return 1;
	return 0;
}

int main () {
    int T;
    SC(T);
    while(T--) {
    	int N;
    	SC(N);
    	VPI A(N);
    	FOR(i, 0, N) {
    		int x, y;
    		SC(x); SC(y);
    		A[i] = make_pair(x, y);
    	}
    	sort(A.begin(), A.end(), cmp);
    	int count = 1, c = 0;
    	FOR(j, 1, N) {
    		if(A[j].first > A[c].second) {
    			count++;
    			c = j;
    		}
    	}
    	printf("%d\n", count);
    } 
    return 0;
}
