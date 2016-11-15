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

void printNGE(const VI &A) {
	int N = A.size(), element;
	stack<int> S;
	S.push(A[0]);
	FOR (i, 1, N) {
		int next = A[i];
		if (S.empty() == false) {
			element = S.top();
			S.pop();
			while (element < next) {
				printf("%d %d\n", element, next);
				if (S.empty()) {
					break;
				}
				element = S.top();
				S.pop();
			}
			if (element > next) {
				S.push(element);
			}
		}
		S.push(next);
	}
	while (S.empty() == false) {
		printf("%d -1\n", S.top());
		S.pop();	
	}
}

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	printNGE(A); 
	return 0;
}