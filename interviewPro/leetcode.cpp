#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
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

int findIndexOfFirstOdd(VI &B, int N) {
	for (int i = 0; i < N; i++) {
		if (B[i]%2) {
			return i;
		}
	}
	return -1;
}

void solve(VI &A, int N) {
	int first = findIndexOfFirstOdd(A, N);
	if (first == -1) {
		sort(A.begin(), A.end());
		return;
	}
	int second = first + 1;
	while (second < N) {
		if (A[second] % 2 == 0) {
			swap(A[first], A[second]);
			first++;
		}
		second++;
	}
	//cout << A[0] << " ";
	sort(A.begin() , A.begin() + first);
	//cout << A[0] << " ";
	sort(A.begin() + first, A.end());
	//cout << A[0] << " ";
	return;
}

int main() {
	int T, N, K;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		VI A;
		FOR (i, 0, N) {
			SC(K);
			A.push_back(K);
		}
		solve(A, N);
		for (int i = 0; i < N; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	return 0;
}





