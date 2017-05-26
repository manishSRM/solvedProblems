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

int findMin(const VI &A, int low, int high) {
    if (high < low) {
        return A[0];
    }
    if (high == low) return A[low];
    int mid = (low + high) / 2;
    if (mid < high && A[mid+1] < A[mid]) {
        return A[mid+1];
    }
    if (mid > low && A[mid] < A[mid-1]) {
        return A[mid];
    }
    if (A[high] > A[mid]) {
        return findMin(A, low, mid-1);
    }
    return findMin(A, mid+1, high);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        VI A(N);
        FOR (i, 0, N) {
            cin >> A[i];
        }
        cout << findMin(A, 0, N-1) << endl;
    }
    return 0;
}











