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

void minHeapify(VI &A, int pos, int heapSize) {
    int minVal = A[pos], minIndex = pos;
    int left = 2*pos + 1;
    int right = 2*pos + 2;
    if (left <= heapSize && A[left] < minVal)
        minIndex = left;
    if (right <= heapSize && A[right] < A[minIndex])
        minIndex = right;
    if (minIndex != pos) {
        swap(A[pos], A[minIndex]);
        pos = minIndex;
        minHeapify(A, pos, heapSize);
    }
    return;
}

void buildMinHeap(VI &A, int N) {
    for (int i = N/2 - 1; i >= 0; i--) {
        minHeapify(A, i, N);
    }
}

void heapSortInDesc(VI &A) {
    int heapSize = A.size() - 1;
    buildMinHeap(A, heapSize);
    for (int i = A.size()-1; i >= 1; i--) {
        swap(A[0], A[i]);
        --heapSize;
        minHeapify(A, 0, heapSize);
    }
}

int main() {
    int N;
    SC(N);
    VI A(N);
    FOR (i, 0, N) {
        SC(A[i]);
    }
    heapSortInDesc(A);
    //buildMinHeap(A, N);
    FOR (i, 0, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}











