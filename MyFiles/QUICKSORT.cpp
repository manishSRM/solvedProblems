#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <set>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#define FOR(A, B, C) for (int A = B; A < C; A++)
#define EFOR(A, B, C) for (int A = B; A <= C; A++)
#define RFOR(A, B, C) for (int A = B; A >= C; A--)
#define lint long long int

using namespace std;

int partition (int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	EFOR(j, p, r - 1) {
		if (A[j] <= x) {
			i += 1;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1], A[r]);
	return (i + 1); 
}

void quickSort (int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main () 
{
	int A[] = {4, 5, 6, 0, 1, 5, 6, 2};
	int size = sizeof (A) / sizeof (int);
	quickSort (A, 0, size - 1);
	FOR(i, 0, size)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}