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
#define MAX 1000002

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;



int main() {
	int T, K;
	SC(T);
	while (T--) {
		SC(K);
		if (K == 1) {
			cout << "0\n";
			continue;
		}
		if (K % 2) {
			cout << (K / 2) + 1 << endl;
 		} else {
 			cout << K - 1 << endl;
		}
	}
	return 0;
}