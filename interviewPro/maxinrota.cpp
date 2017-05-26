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

int search(VI A, int l, int h) {
    if (l == h) return A[l];

    if (h == l+1 && A[l] > A[h]) return A[l];
    if (h == l+1 && A[l] < A[h]) return A[h];

    int mid = (l+h) / 2;
    if (A[mid] > A[mid+1] && A[mid] > A[mid-1]) return A[mid];

    if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1]) {
        return search(A, l, mid-1);
    } else {
        return search(A, mid+1, h);
    }
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
        int ans = search(A, 0, N-1);
        cout << ans << endl;
    }
    return 0;
