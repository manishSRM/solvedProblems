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
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int main () {
    int T, R, G, B, M;
    SC(T);
    while(T--) {
    	SC(R); SC(G); SC(B); SC(M);
    	int Red[R + 1], Green[G + 1], Blue[B + 1];
        char c;
    	EFOR(i, 1, R)
    		SC(Red[i]);
        EFOR(j, 1, G)
    		SC(Green[j]);
        EFOR(k, 1, B)	
    		SC(Blue[k]);
        sort(Red + 1, Red + R + 1);
    	sort(Green + 1, Green + G + 1);
    	sort(Blue + 1, Blue + B + 1);		
    	FOR(i, 0, M) {
            int maxRed = Red[R], maxGreen = Green[G], maxBlue = Blue[B];
            int M1 = maxRed, M2 = maxGreen, M3 = maxBlue;
    	    int superMax = max(maxRed, max(maxGreen, maxBlue));
            if(superMax == M1) {
                EFOR(i, 1, R)
                    Red[i] /= 2;
            } else if(superMax == M2) {
                EFOR(j, 1, G)
                    Green[j] /= 2;
            } else if (superMax == M3) {
                EFOR(k, 1, B) 
                    Blue[k] /= 2;
            }
                 
        }
        printf("%d\n", max(Red[R], max(Green[G], Blue[B])));  
    }
    return 0;
}
