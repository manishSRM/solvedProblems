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

int partition (VI &A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	EFOR(j, p, r - 1) {
		if (A[j] <= x) {
			i += 1;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1], A[r]);
	return (i + 1);
}

void quickSort (VI &A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main () {
	int N;
	SC(N);
	VI A(N);
	FOR (i, 0, N) {
		SC(A[i]);
	}
	quickSort (A, 0, N-1);
	FOR(i, 0, N)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}