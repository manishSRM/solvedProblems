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

set<pair<int, int> > S;
int a_max, b_max;

inline int isThisPairExist(int a, int b) {
	return (S.find(make_pair(a, b)) != S.end()) ? 0 : 1;
}

void currentSet() {
	set<pair<int, int> > :: iterator it = S.begin();
	for (; it != S.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}
}

int minimumStepTogain_C(int a, int b, int &c) {
	if ((!S.empty() && isThisPairExist(a, b)) || (a_max < c && b_max < c)) {
		return 0;
	}
	cout << a << " " << b << " " << c << endl;
	if (a == c || b == c) {
		return 1;
	}
	currentSet();
	S.insert(make_pair(a, b));
	
	if (a > b) { swap(a ,b); }
	if (a > 0 && a < a_max) {
        return (minimumStepTogain_C(a_max, (b - a), c));
    }
    return (minimumStepTogain_C(0, b, c) || minimumStepTogain_C(a_max, b, c));
}

int main() {
	int a, b, c;
	SC(a); SC(b); SC(c);
	a_max = a;
	b_max = b;
	cout << minimumStepTogain_C(a, b, c) << endl;
	return 0;
}