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

bool cmp(pair<int, int> &A, pair<int, int> &B) {
	return (A.second > B.second);
}

void sortByFrequency(const VI &A) {
	int N = A.size(), len = 0;
	MP myMap;
	FOR (i, 0, N) {
		MP :: iterator foundIt = myMap.find(A[i]);
		if (foundIt != myMap.end()) {
			int prev = foundIt -> second;
			myMap.erase(foundIt);
			myMap[A[i]] = prev + 1;
		} else {
			myMap[A[i]] = 1;
		}
	}
	VPI frequency;
	MP :: iterator it = myMap.begin();
	for (; it != myMap.end(); ++it) {
		frequency.push_back(make_pair(it -> first, it -> second));
		len++;
	}
	sort(frequency.begin(), frequency.end(), cmp);
	FOR (i, 0, len) {
		FOR (j, 0, frequency[i].second) {
			printf("%d ", frequency[i].first);
		}
	}
	printf("\n");
	return;
}

int main() {
	int N, K;
	SC(N);
	VI A;
	FOR (i, 0, N) {
		SC(K);
		A.push_back(K);
	}
	sortByFrequency(A);
	return 0;
}