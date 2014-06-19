#include <cstdio>
#include <iostream>
#define MAX 100000

using namespace std;

int A[MAX]; 

void intializeSegTree (int node, int min, int max, int A[]) {
	if (min == max) {
		if (A[min] % 3 == 0)
			segTree[node] = 1;
		else
			segTree[node] = 0;
	}
	else {
		int mid = (min + max) / 2;
		intializeSegTree (2 * node, min, mid, A);
		intializeSegTree (2 * node + 1, mid + 1, max, A);
		segTree[node] = segTree[2 * node] + segTree[2 * node + 1];  
	}
}

int queryCount (int node, int min, int max, int a, int b) {
	if (a > max || b < min)
		return 0;
	if (min >= a && max <= b)
		return segTree[node];
	int mid = (min + max) / 2;
	int t1 = queryCount (2 * node, min, mid, a, b);
	int t2 = queryCount (2 * node + 1, mid + 1, max, a, b);
	return t1 + t2;
}

int main () {
	int N, Q;
	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
		scanf ("%d", &A[i]);
	intializeSegTree (1, 0, N - 1, A);
	scanf ("%d", &Q);
	for (int j = 0; j < Q; j++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		printf("%d\n", queryCount (1, 0, N - 1, a, b));
	}
	return 0;
}