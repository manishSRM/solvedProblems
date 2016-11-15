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

bool isThisMAxHere(int A, int B) {
	return (A > B);
}
 
void printLeaders(const VI &A) {
	int size = A.size(), MAX = INT_MIN;
	RFOR(i, size - 1, 0) {
		if (isThisMAxHere(A[i], MAX)) {
			printf("%d\n", A[i]);
			MAX = A[i];
		}
	}
	return;
}

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	printLeaders(A);
	return 0;
}