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
  	int T, A[12];
  	char str[12], C;
  	SC(T);
  	while(T--) {
  		scanf("%c%s", &C, str);
  		for(int i = 0; str[i] != '\0'; i++)
  			A[i] = str[i] - '0';
 		int count = 0, number = A[0];
  		FOR(j, 1, strlen(str)) {
  			number = number * 10 + A[j];
  			if(number <= 26) 
  				count++;
  			//printf("%d\n", number);
  			number = A[j];
  		}
  		printf("%d\n", count + 1);
  	}
    return 0;
}
