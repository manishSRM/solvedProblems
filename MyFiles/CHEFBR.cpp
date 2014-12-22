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

int checksubSetBalanced(const VI &A) {
	if(A.size() == 0 || A[0] > 0) {
        return 0;
    }
    stack<int> myStack;
    myStack.push(A[0]);
    FOR(i, 1, A.size()) {
        if(A[i] > 0 && myStack.size() > 0) {
            int temp = myStack.top();
            if(temp != (-A[i]))
                return 0;
            myStack.pop();
        } else {
            myStack.push(A[i]);
        }
    }
    if(!myStack.size())
        return 1;
    return 0;
}

int isBitSet (int mask, int k) {
    return ((mask & (1 << k)) != 0);
}

int countBalancedSubset (const VI &A, int n) {
	int count = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		VI subsetElement;
		for(int k = 0; k < n; k++) {
			if(isBitSet(mask, k)) {
				subsetElement.push_back(A[k]);	
			}
		}
		if(checksubSetBalanced(subsetElement))
			count++;
	}
	return (count + 1);	
}

int main () {
    int N;
    SC(N);
    VI A(N);
    FOR(i, 0, N) {
    	SC(A[i]);
    }
    printf("%d\n", countBalancedSubset(A, N)); 
    return 0;
}
