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

void BFS(VI &shortestDistance, int N, const VVI &edgeList, int s) {
    VI vertices(N + 1, false);  
    queue<int> Q;
    Q.push(s);
    vertices[s] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        FOR(i, 0, edgeList[u].size()) {
            int v = edgeList[u][i];
            if(vertices[v] != true) {
                vertices[v] = true;
                Q.push(v);
                shortestDistance[v] = shortestDistance[u] + 1;
            }
        }
    }
}

void findPath(VVI &storePath, const VVI &edgeList, int A, int N) {
    VI vertices(N + 1, false);
    queue<int> Q;
    Q.push(A);
    vertices[A] = true;
    storePath[A][A] = A;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        FOR(i, 0, edgeList[u].size()) {
            int v = edgeList[u][i];
            if(vertices[v] != true) {
                Q.push(v);
                vertices[v] = true;
                storePath[A][v] = u;
            }
        }
    }
}
void trackPath(VI &intermediateCity, const VVI &storePath, int A, int C) {
    intermediateCity.push_back(C);
    if(A == C) {
        return;
    }
    int temp = C;
    while(storePath[A][temp] != A) {
        temp = storePath[A][temp];
        intermediateCity.push_back(temp);
    }
    intermediateCity.push_back(A);
}

void solvedQuery(const VI &shortestDistance, const VVI &storeCityInProduct, const VVI &storePath, int A, int P) {
    int bestMinDistance = INT_MIN;
    int answer, city;
    FOR(i, 0, storeCityInProduct[P].size()) {
        city = storeCityInProduct[P][i];
        VI intermediateCity;
        trackPath(intermediateCity, storePath, A, city);
        int minimum = INT_MAX;
        FOR(j, 0, intermediateCity.size()) {
            minimum = min(minimum, shortestDistance[intermediateCity[j]]);
        }
        if(bestMinDistance < minimum) {
            bestMinDistance = minimum;
            answer = city;
        } else if(bestMinDistance == minimum) {
            answer = min(answer, city);
        }
    }
    printf("%d\n", answer);
}

int main () {
    int capital, N, K;
    SC(N); SC(K);
    SC(capital);
    VVI edgeList(N + 1);
    VVI storePath(N + 1, vector<int>(N + 1));
    EFOR(i, 1, (N - 1)) {
        int x, y;
        SC(x); SC(y);
        edgeList[x].push_back(y);
        edgeList[y].push_back(x);
    } 

    EFOR(k, 1, N) {
        findPath(storePath, edgeList, k, N);
    }

    VVI storeCityInProduct(K + 1);
    EFOR(j, 1, N)  {
        int C;
        SC(C);
        storeCityInProduct[C].push_back(j);
    }

    VI shortestDistance(N + 1, 0);
    BFS(shortestDistance, N, edgeList, capital);
    int Q;
    SC(Q);
    while(Q--) {
        int A, P;
        SC(A); SC(P);
        if(P > K || storeCityInProduct[P].size() == 0) {
            printf("-1\n");
            continue;
        }
        solvedQuery(shortestDistance, storeCityInProduct, storePath, A, P);
    }     
    return 0;
}
