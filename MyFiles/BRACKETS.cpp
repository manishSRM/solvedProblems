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

#define MAX 100004
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

int FUNCTION(char *str) {
	int balance = 0, maxBalance = 0;
	FOR(i, 0, strlen(str)) {
		if(str[i] == '(') balance++;
		if(str[i] == ')') balance--;
		maxBalance = max(maxBalance, balance);
	}
	return maxBalance;
}

int main () {
    int T;
    SC(T);
    while(T--) {
    	char str[MAX];
    	scanf("%s", str);
    	int l = FUNCTION(str);
    	//printf("%d\n", l);
    	EFOR(i, 1, l) 
    		printf("(");
    	EFOR(j, 1, l) 
    		printf(")");		
    	printf("\n");
    } 
    return 0;
}
