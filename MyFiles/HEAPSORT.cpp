
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

void Max_Heapify (VI &A, int pos, int heap_size) {
    int larger = pos;
    int left = (pos << 1) + 1;
    int right = (pos << 1) + 2;
    if (left < heap_size && A[left] > A[larger])
        larger = left;
    if (right < heap_size && A[right] > A[larger])
        larger = right;
    if (larger != pos) {
        swap(A[pos], A[larger]);
        Max_Heapify(A, larger, heap_size);
    }
}

void Build_Max_Heap (VI &A) {
    RFOR (pos, (A.size()/2)-1, 0)
        Max_Heapify (A, pos, A.size());
    return;
}

void heapSort (VI &A) {
    int heapSize = A.size();
    Build_Max_Heap (A);
    RFOR (pos, A.size()-1, 1) {
        swap (A[0], A[pos]);
        --heapSize;
        Max_Heapify (A, 0, heapSize);
    }
    return;
}

int main () {
    int N;
    SC(N);
    VI A(N);
    FOR(i, 0, N)
        SC(A[i]);
    heapSort (A);
    FOR(j, 0, N)
        printf("%d ", A[j]);
    cout << endl;
    return 0;
}