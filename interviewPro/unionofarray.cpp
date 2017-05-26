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

void pushElement(VI &temp, int val, int &currentSize) {
	temp.push_back(val);
	currentSize++;	
}

VI doUnion(const VI &A, const VI &B) {
	int M = A.size();
	int N = B.size();
	int	maxSize = max(M, N);
	VI result;
	int currentSize = -1;
	if (A[0] != B[0]) {
		pushElement(result, A[0], currentSize);
		pushElement(result, B[0], currentSize);
		if (result[0] > result[1]) {
			swap(result[0], result[1]);
		}
	} else {
		pushElement(result, A[0], currentSize);
	}
	FOR (i, 1, maxSize) {
		if (i < M && i < N) {
			if (result[currentSize] != A[i]) {
				pushElement(result, A[i], currentSize);
			} 
			if (result[currentSize] != B[i]) {
				pushElement(result, B[i], currentSize);
			}
		} else if (i < M) {
			if (result[currentSize] != A[i]) {
				pushElement(result, A[i], currentSize);
			}
		} else {
			if (result[currentSize] != B[i]) {
				pushElement(result, B[i], currentSize);
			}
		}
	}
	return result;
} 

int main() {
	int M, N, K;
	SC(M); SC(N);
	VI V1, V2;
	FOR (i, 0, M) {
		SC(K);
		V1.push_back(K);
	}
	FOR (i, 0, N) {
		SC(K);
		V2.push_back(K);	
	}
	VI V3 = doUnion(V1, V2); 
	FOR (j, 0, V3.size()) {
		cout << V3[j] << " "; 
	}
	cout << endl;
	return 0;
} 