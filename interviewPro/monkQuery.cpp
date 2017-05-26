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

#define MAX 100002
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

vector<int> C(MAX, 0);

int main() {	
	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int> >minQ;
	int Q, operation, X;
	SC(Q);
	while (Q--) {
		SC(operation);
		if (operation == 1) {
			SC(X);
			C[X]++;
			maxQ.push(X);
			minQ.push(X);
		} else if (operation == 2) {
			SC(X);
			if (C[X]) {	
				C[X]--;
			} else {
				cout << "-1\n";
			}
		} else if (operation == 3) {
			while (maxQ.size() && C[maxQ.top()] == 0) {
				maxQ.pop();
			}
			if (maxQ.size()) {
				cout << maxQ.top() << endl;
			} else {
				cout << "-1\n";
			}
		} else {
			while (minQ.size() && C[minQ.top()] == 0) {
				minQ.pop();
			} 
			if (minQ.size()) {
				cout << minQ.top() << endl;
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}