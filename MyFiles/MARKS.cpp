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
#define SCC(C) scanf("%c", &C)
#define SC(A) scanf("%d", &A)
#define PF(A) scanf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VII;

int overGivenMarks(const VI &l) {
	VI sub(102, 0);
	if(!l.size())
		return 0;
	int size = l.size();		 
	FOR(i, 0, size) 
		sub[l[i]]++;
	VI marksPercent;
	int maxCount = 0;
	EFOR(j, 0, 100) 
		maxCount += sub[j];
	EFOR(k, 0, 100) {
		int f = (sub[k] * 100);
		if(f > 10 * maxCount) 
			marksPercent.push_back(k);
	}
	if(!marksPercent.size())
		return 0;
	sort(marksPercent.begin(), marksPercent.end());
	int size2 = marksPercent.size();
	FOR(i, 0, size2) 
		printf("%d ", marksPercent[i]);
	printf("\n");
	return 1;	
}

int main () {
    int N, marks;
    char C1, c;
    SC(N);
  	VII list(71);
    while(N--) {
    	SCC(C1); SCC(c); SC(marks);
    	int m = c;
    	list[m].push_back(marks);	
    }
    EFOR(i, 65, 69) { 
    	if(!overGivenMarks(list[i]))
    		printf("Nothing Unusual\n");
    }	
    return 0;
}
