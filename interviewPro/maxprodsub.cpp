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
typedef pair<PI, int> PII;

int search(VI A, int N) {
    int maxEndHere = 1;
    int minEndHere = 1;
    int maxSoFar = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            maxEndHere = maxEndHere*A[i];
            minEndHere = min (minEndHere * A[i], 1);
        } else if (A[i] == 0) {
            maxEndHere = 1;
            minEndHere = 1;
        } else {
            int temp = maxEndHere;
            maxEndHere = max(minEndHere*A[i], 1);
            minEndHere = temp * A[i];
        }

        maxSoFar = max(maxSoFar, maxEndHere);
    }
    return maxSoFar;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N;
        vector<int> A(N);
        FOR (i, 0, N) {
            cin >> A[i];
        }
        int ans = search(A, N);
        cout << ans << endl;
    }
    return 0;
}
