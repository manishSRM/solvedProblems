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
#define PF(A) scanf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;
typedef set<int> ST;

int main () {
    int N, M;
    SC(N);
    VI A (N + 1);
    set<int> myset[6];
    EFOR(i, 1, N) {
    	SC(A[i]);
        if(A[i] % 2 == 0) myset[2].insert(i);
        if(A[i] % 3 == 0) myset[3].insert(i);
        if(A[i] % 5 == 0) myset[5].insert(i);
    }    
    SC(M);
    int query, l, r, p, d;
    while(M--) {
    	SC(query);
    	if(query == 1) {
    		SC(l); SC(r); SC(p);
            vector<int> deleteFromSet;
            set<int>::iterator it = lower_bound(myset[p].begin(), myset[p].end(), l);
            for(; it != myset[p].end(); it++) {
                if(*it > r)
                    break;
                A[*it] /= p;
                if(A[*it] % p)
                    deleteFromSet.push_back(*it);     
            }
            for(vector<int>::iterator it = deleteFromSet.begin(); it != deleteFromSet.end(); it++) 
                myset[p].erase(*it);
    	}
    	else {
    		SC(l);SC(d);
    		if(A[l] % 2 == 0) myset[2].erase(l);
            if(A[l] % 3 == 0) myset[3].erase(l);
            if(A[l] % 5 == 0) myset[5].erase(l);

            if(d % 2 == 0) myset[2].insert(l);
            if(d % 3 == 0) myset[3].insert(l);
            if(d % 5 == 0) myset[5].insert(l);
    	    A[l] = d;
        }
    }
    EFOR(j, 1, N)
    	printf("%d ", A[j]);
    printf("\n");		
    return 0;
}
