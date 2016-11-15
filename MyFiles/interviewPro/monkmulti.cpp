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
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d\n", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

void max_heapify(vector<int> &A, int i, int N) {
	int left = 2 * i;
	int right = 2 * i + 1, largest;
	if (left <= N && A[left] > A[i]) {
		largest = left;
	} else {
		largest = i;
	}
	if (right <= N && A[right] > A[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		max_heapify(A, largest, N);
	}
}

void build_heap(vector<int> &heap, int N) {
	for (int i = N / 2; i >= 1; i--) {
		max_heapify(heap, i, N);
	}
}

bool cmp(int &A, int &B) {
	return A > B;
}

int main() {
	int N, K, size = 4;
	SC(N);
	vector<int> res;
	vector<int> heap(size + 1);
	EFOR (i, 1, N) {
		SC(K);
		if (i < size - 1) {
			heap[i] = K;
			res.push_back(-1);
		} else if (i == size - 1) {
			heap[i] = K;
			build_heap(heap, i);
			res.push_back(heap[1] * heap[2] * heap[3]);
		} else {
			heap[size] = K;
			sort(heap.begin() + 1, heap.begin() + size + 1, cmp);
			res.push_back(heap[1] * heap[2] * heap[3]);
		}
	}
	for (int j = 0; j < res.size(); j++) {
		cout << res[j] << endl;
	} 
	return 0;
}