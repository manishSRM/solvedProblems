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
#include <time.h>

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

// algo used to find ith largest or smallest element in an array O(N)

int partition(VI &A, int left, int right, int pivot) {
    while (true) {
        while (left <= right && A[left] <= pivot) {
            left++;
        }
        while (left <= right && A[right] > pivot) {
            right--;
        }
        if (left > right) {
            return left-1;
        }
        swap(A[left], A[right]);
    }
}

int selectionAlgo(VI &A, int left, int right, int rank) {
    int pivot = A[rand() % (right - left + 1) + left];
    int leftEnd = partition(A, left, right, pivot);
    int leftSize = leftEnd - left + 1;
    if (leftSize == (rank)) {
        return max(A[left], A[leftEnd]);
    } else if (rank < leftSize) {
        return selectionAlgo(A, left, leftEnd, rank);
    } else {
        return selectionAlgo(A, (leftEnd + 1), right, (rank - leftSize));
    }
}

int main() {
    srand(time(NULL));
    int T;
    SC(T);
    while (T--) {
        int N, rank;
        SC(N); SC(rank);
        VI A(N);
        FOR (i, 0, N) {
            SC(A[i]);
        }
        cout << selectionAlgo(A, 0, (N-1), rank) << endl;
    }
    return 0;
}






