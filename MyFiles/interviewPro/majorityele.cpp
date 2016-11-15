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

int binarySearch(VI &B, int low, int high, int search) {
	if (low < high) {
		int mid = (high + low) / 2;
		if ((mid == 0 || search > B[mid - 1]) && (B[mid] == search)) {
			return mid;
		} else if (search > B[mid]) {
			binarySearch(B, mid + 1, high, search);
		} else {
			binarySearch(B, low, mid - 1, search);
		}
	}
	return -1;	
}

bool isMajority_X(VI &A, int X) {
	int N = A.size();
	int i = binarySearch(A, 0, N - 1, X);
	if (i == -1) {
		return false;
	}
	cout << i << endl;
	if (i + N / 2 <= N - 1 && A[i + N / 2] == X) {
		return true;
	} else {
		return false;
	}			
}

int main() {
	int N, K, X;
	SC(N); 
	VI A;
	FOR (i, 0, N) { 
		SC(K);
		A.push_back(K);
	}
	SC(X);
	cout << isMajority_X(A, X) << endl;
	return 0;
} 