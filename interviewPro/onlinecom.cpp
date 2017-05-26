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

void storeBinary(VVI &A, int N) {
	VI B;
	while (N) {
		B.push_back(N % 2);
		N >>= 1;
	}
	int size = A.size();
	A.push_back(B);
}

bool isItVeryCool(VI B, int K) {
	int size = B.size(), c = 0;
	for (int i = 0; i < size - 2;) {
		if (B[i] + B[i + 1] + B[i + 2] == 2 && B[i + 1] == 0) {
			c++;
			i += 2;
		} else {
			i += 1;
		}
	}
	return (c >= K);
}

int main() {
	int T;
	SC(T);
	while (T--) {
		int R, K;
		SC(R); SC(K);
		VVI A;
		EFOR (i, 1, R) {
			storeBinary(A, i);
		}
		int count = 0;
		FOR (i, 0, A.size()) {
			if (isItVeryCool(A[i], K)) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
} 