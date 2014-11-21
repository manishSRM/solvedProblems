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
#define MAX 100010
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
    char str[MAX], C;
    int T;
    SC(T);
    while(T--) {
    	scanf("%c%s", &C, str);
    	VI A(150, 0);
    	int count = 0;
    	for(int i = 0; str[i] != '\0'; i++) 
    		A[int(str[i])]++;
    	for(int j = 97; j <= 125; j++) {
    		if(A[j] != 0)
    			count++;
    	}
    	printf("%d\n", count);
    }
    return 0;
}
