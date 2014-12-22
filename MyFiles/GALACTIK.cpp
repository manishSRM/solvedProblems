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
#define MAX 10002

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

void MAKE_SET(VI &parent, int x) {
    parent[x] = x;
}

int FIND_SET(VI &parent, int x) {
    if(parent[x] == x) 
        return x;
    return (parent[x] = FIND_SET(parent, parent[x]));
}

void UNION_SET(VI &parent, VI &taxOfEachPlanet, int x, int y) {
    int parentOfX = FIND_SET(parent, x);
    int parentOfY = FIND_SET(parent, y);
    if(parentOfY == parentOfX)
        return;
    if(taxOfEachPlanet[parentOfX] < taxOfEachPlanet[parentOfY]) {
        parent[parentOfY] = parentOfX;
    } else {
        parent[parentOfX] = parentOfY;
    }
}   

void createForest(VI &parent, int N) {
    EFOR(i, 1, N) {
        MAKE_SET(parent, i);
    }
    return;
}

void mergeSets(const VPI &edgeList, VI &parent, VI &taxOfEachPlanet) {
    FOR(k, 0, edgeList.size()) {
        int x = edgeList[k].first;
        int y = edgeList[k].second;
        UNION_SET(parent, taxOfEachPlanet, x, y);
    }
    return;
}

void estimateMinimumCost(VI &taxOfEachPlanet, const VI &parent, int N) {
    lint minimumCost = 0;
    int totalSets = 0;
    bool check = 1;
    int bestMinimum = INT_MAX;
    EFOR(i, 1, N) {
        if(parent[i] == i) {
            totalSets++;
            if(taxOfEachPlanet[i] == INT_MAX) {
                check = 0;
                break;
            } else {
                minimumCost += taxOfEachPlanet[i];
                bestMinimum = min(bestMinimum, taxOfEachPlanet[i]);
            }
        }
    }
    if(totalSets == 1) {
        printf("0\n");
        return;
    }
    if(!check) {
        printf("-1\n");
        return;
    }
    printf("%lld\n", ((totalSets - 2) * bestMinimum) + minimumCost);
    return;
}

int main () {
    int N, M;
    SC(N); SC(M);
    VPI edgeList;
    VI taxOfEachPlanet(N + 1);
    VI parent(N + 1);
    EFOR(i, 1, M) {
        int u, v;
        SC(u); SC(v);
        edgeList.push_back(make_pair(u, v));
    }
    EFOR(j, 1, N) {
        SC(taxOfEachPlanet[j]);
        if(taxOfEachPlanet[j] < 0)  
            taxOfEachPlanet[j] = INT_MAX;
    }
    createForest(parent, N);
    mergeSets(edgeList, parent, taxOfEachPlanet);
    estimateMinimumCost(taxOfEachPlanet, parent, N);
    return 0;
}    
    