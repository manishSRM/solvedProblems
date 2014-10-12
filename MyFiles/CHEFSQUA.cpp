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
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

PI generateFirstPoints (const PI &a, const PI &b) {
	return make_pair((a.first + b.first + b.second - a.second) / 2, (a.second + b.second + a.first - b.first) / 2);
}

PI generateSecondPoints (const PI &a, const PI &b) {
	return make_pair((a.first + b.first + a.second - b.second) / 2, (a.second + b.second + b.first - a.first) / 2);
}

int main () {
    int N, x, y, Count;
    SC(N);
    if(N < 2) {
    	printf("%d\n", 4 - N);
    	return 0;
    }
    set<PI> points;
    VPI P; 
    while(N--) {
    	SC(x); SC(y);
    	x *= 2; y *= 2;
    	PI point = make_pair(x, y);
    	points.insert(point);
    	P.push_back(point);
    }
    int size = P.size(), minimum = INT_MAX;
    FOR (i, 0, size) {
    	int x1 = P[i].first, y1 = P[i].second;
    	FOR (j, i + 1, size) {
    		Count = 2;
    		int x2 = P[j].first, y2 = P[j].second;
    		PI p1 = generateFirstPoints(make_pair(x1, y1), make_pair(x2, y2));
    		PI p2 = generateSecondPoints(make_pair(x1, y1), make_pair(x2, y2));
    		if(points.count(p1) != 0)
    			Count--;
    		if(points.count(p2) != 0) 
    			Count--;
	 	
	    	if(minimum > Count)
	    		minimum = Count;
    	}
    }
   	printf("%d\n", minimum);
    return 0;
}
