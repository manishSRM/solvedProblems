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

struct pairIndex {
	int first;
	int second;
};

inline int MOD(int num) {
	return (num < 0) ? (num * (-1)) : num;
}
	
void closeToZeroNumbers(VI &A) {
	int N = A.size();
	sort(A.begin(), A.end());
	int l = 0, r = N - 1;
	int sum = INT_MAX, first, second; 
	while (l < r) {
		int current = MOD(A[l] + A[r]);
		if (current < sum) {
			sum = current;
			first = l;
			second = r;
		}
		if ((A[l] + A[r]) > 0) {
			r--;
		} else {
			l++;
		}	
	}
	cout << sum << " " << first << " " << second << endl;
}

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	closeToZeroNumbers(A);
	return 0;
}