#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>

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
typedef pair<int, pair<int, int> > PP;
typedef vector<PP> VPP;

void MAKE_SET(VI &parent, VI &setSize, int x) {
	parent[x] = x;
	setSize[x] = 1;
}

int FIND_SET(VI &parent, int x) {
	if(parent[x] == x) {
		return x;
	}
	return (parent[x] = FIND_SET(parent, parent[x]));        //path compression
}

void UNION_SET(VI &parent, int x, int y, VI &setSize) {
	int parentOfX = FIND_SET(parent, x);
	int parentOfY = FIND_SET(parent, y);
	if(parentOfY == parentOfX) {
	    return;
	}
	if (setSize[parentOfX] < setSize[parentOfY]) {
	    swap(parentOfX, parentOfY);
	}
	parent[parentOfY] = parentOfX;
	setSize[parentOfX] += setSize[parentOfY];
	return;
}

int cmp(const PP &A, const PP &B) {
	if(A.second.second < B.second.second)
		return 1;
	return 0;
}

void Kruskal(VPP &edgeList, int N, VPP &resultVector, VI &parent, VI &setSize) {
	EFOR(i, 1, N) {
		MAKE_SET(parent, setSize, i);
	}
	sort(edgeList.begin(), edgeList.end(), cmp);
	FOR(i, 0, edgeList.size()) {
		int u = edgeList[i].first;
		int v = edgeList[i].second.first;
		if(FIND_SET(parent, u) != FIND_SET(parent, v)) {
			resultVector.push_back(edgeList[i]);
			UNION_SET(parent, u, v, setSize);
		}
	}
	return;
}

int main() {
	int N, E;
	SC(N); SC(E);
	VPP edgeList(N + 1);
	VPP resultVector;
	VI parent(N + 1);
	VI setSize(N + 1);                         //for union by rank
	EFOR(i, 1, E) {
		int u, v, w;
		SC(u); SC(v); SC(w);
		edgeList.push_back(make_pair(u, make_pair(v, w)));
	}
	Kruskal(edgeList, N, resultVector, parent, setSize);
	FOR(j, 0, resultVector.size()) {
		printf("%d %d\n", resultVector[j].first, resultVector[j].second.first);
	}
 	return 0;
}