#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <sstream>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <deque>
#include <bitset>
#include <map>
#include <assert.h>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

void shiftRight(VI &temp) {
	int size = temp.size();
	int lastIndexStatus = size - 1;
	RFOR(i, size - 1, 0) {
		if (temp[i] != -1) {
			if (i == lastIndexStatus) {
				lastIndexStatus--;
			} else {
				temp[lastIndexStatus] = temp[i];
				temp[i] = -1;
				lastIndexStatus--;
			}	 
		}
	}
}

// only merge arrays is remaining..i think this not so tough

int main() {
	int m, n, K;
	VI mPlusn, N;
	SC(m); SC(n);
	FOR (i, 0, (m + n)) {
		SC(K);
		mPlusn.push_back(K);	
	}
	FOR (i, 0, n) {
		SC(K);
		N.push_back(K);
	}
	mergeNIntomPlusn(mPlusn, N);
	return 0;
}