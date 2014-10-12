#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SCC(A) scanf("%c", &A)
#define SC(A) scanf("%d", &A)
#define PF(A) scanf("%d", A)
#define MOD 1000000009

using namespace std;

typedef vector<bool> VB;
typedef pair<char, int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

void findOutIntervals(vector<lint> &intervals, const VPI &P, int N, int M) {
	int presentIndex = P[0].second;
	char latestColour = P[0].first;
	FOR(i, 1, M) {	
		if(P[i].first != latestColour) {
			latestColour = P[i].first;
			intervals.push_back(P[i].second - presentIndex);
			presentIndex = P[i].second;
			//printf("%c %d\n", latestColour, presentIndex);
		}
		else 
			presentIndex = P[i].second; 
	}
}

void totalCombinations(const vector<lint> &intervals) {
	lint tatalCombo = 1;
	FOR(i, 0, intervals.size()) {
		tatalCombo = (tatalCombo * intervals[i]) % MOD; 
	}
	printf("%lld\n", tatalCombo);
}

int cmp (const PI &a, const PI &b) {
	if(a.second > b.second)
		return 0;
	return 1;
}

int main () {
	int T, y, N, M;
	char c, C1;
	SC(T);
	while(T--) {
		SC(N); SC(M);
		VPI paintIndex;
		FOR(i, 0, M) {
			SCC(C1); SCC(c); SC(y);
			paintIndex.push_back(make_pair(c, y));
		}
		sort(paintIndex.begin(), paintIndex.end(), cmp);
		//printf("%c %d\n", paintIndex[4].first, paintIndex[4].second);
		vector<lint> intervals;
		findOutIntervals(intervals, paintIndex, N, M);
		totalCombinations(intervals);
	}    
    return 0;
}
