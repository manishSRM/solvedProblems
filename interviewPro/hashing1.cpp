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
#define SCL(A) scanf("%lld", &A)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)
#define MOD 1000000007

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

vector<int> inputArray() {
    int N;
    SC(N);
    vector<int> A(N);
    FOR (i, 0, N) {
        SC(A[i]);
    }
    return A;
}

void solve(VI &A) {
    map<int, int> myMap;
    map<int, int> :: iterator it;
    FOR (i, 0, A.size()) {
        it = myMap.find(A[i]);
        if(it != myMap.end()) {
            it->second = it->second + 1;
        } else {
            myMap[A[i]] = 1;
        }
    }
    FOR (i, 0, A.size()) {
        it = myMap.find(A[i]);
        if (it != myMap.end()) {
            FOR (j, 0, it->second) {
                cout << A[i] << " ";
            }
            myMap.erase(it);
        }
    }
    cout << endl;
}

//problem : The grouping should happen in a way that the order of first occurrences of all elements is maintained.
//Input: arr[] = {5, 3, 5, 1, 3, 3}
//Output:        {5, 5, 3, 3, 3, 1}

//#hashing
int main() {
    int T;
    SC(T);
    while (T--) {
        vector<int> A = inputArray();
        solve(A);
    }
    return 0;
}


