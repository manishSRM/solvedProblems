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

// for finding thw majority element index

void moores_voting_algo(const VI &A, int &N) {
	int maxIndex = 0, count = 1;
	FOR (i, 1, N) {
		if (A[maxIndex] == A[i]) {
			count++;
		} else {
			count--;
		}
		if (count == 0) {
			maxIndex = i;
			count = 1;
		}
	}
	cout << maxIndex << endl;
} 

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	moores_voting_algo(A, N);
	return 0;
}