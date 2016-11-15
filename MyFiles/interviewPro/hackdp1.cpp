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

int N;

int maxProfit(VVI &M, VI &A, int beg, int end) {
	if(beg > end) {
		return 0;
	} else if (M[beg][end] != -1) {
		return M[beg][end];
	}
	int year = N - (end -  beg + 1) + 1;
	M[beg][end] = max(maxProfit(M, A, beg + 1, end) + year * A[beg], maxProfit(M, A, beg, end - 1) + year * A[end]);
	return M[beg][end];
}

int main() {
	cin >> N;
	vector<vector<int> >M(N, vector<int>(N, -1));
	VI A(N);
	FOR(i, 0, N) {
		SC(A[i]);
	}
	cout << maxProfit(M, A, 0, N - 1) << endl;
	FOR (i, 0, N) {
		FOR (j, 0, N) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
