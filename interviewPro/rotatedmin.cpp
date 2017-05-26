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

int search(VI A, int l, int h, int key) {
    if (l > h) {
        return -1;
    }
    int mid = (l + h) / 2;
    if (A[mid] == key) {
        return mid;
    }
    if (A[l] <= A[mid]) {
        if (key >= A[l] && key <= A[mid]) {
            return search(A, l, mid-1, key);
        }
        return search(A, mid+1, h, key);
    }
    if (key >= A[mid] && key <= A[h]) {
        return search(A, mid+1, h, key);
    }
    return search(A, l, mid-1, key);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        FOR (i, 0, N) {
            cin >> A[i];
        }
        int ans = search(A, 0, N-1, K);
        if (ans == -1) {
            cout << "OOPS! NOT FOUND\n";
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
