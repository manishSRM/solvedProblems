#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
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

int find(VI &Parent, int i) {
    if (Parent[i] == -1) {
        return i;
    }
    return find(Parent, Parent[i]);
}

void Union(VI &Parent, int x, int y) {
    int xset = find(Parent, x);
    int yset = find(Parent, y);
    Parent[xset] = yset;
}

bool isCycle(const VPI &Edges, int V) {
    vector<int> Parent(V, -1);
    FOR (i, 0, Edges.size()) {
        int x = find(Parent, Edges[i].first);
        int y = find(Parent, Edges[i].second);
        if (x == y) {
            return 1;
        }
        Union(Parent, x, y);
    }
    return 0;
}

int main() {
    int V, E;
    cin >> V >> E;
    VPI Edges;
    FOR (i, 0, E) {
        int u, v;
        cin >> u >> v;
        Edges.push_back(make_pair(u, v));
    }
    cout << isCycle(Edges, V) << endl;
    return 0;
}









