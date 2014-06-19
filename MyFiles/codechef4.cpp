#include <stdio.h>

using namespace std;

int checkMin (int A[], int startIndex, int endIndex, int m) {
	int small = A[startIndex];
    for (int i = startIndex; i <= endIndex; i++) {
		if (small > A[i])
			small = A[i];
    }
    if (small == m)
		return 1;
	return 0;
}

int solve (int A[], int n, int k) {
	int total = 0;
    for (int startIndex = 0; startIndex < n; startIndex++) {
        for (int endIndex = startIndex; endIndex < n; endIndex++) {
        	total += checkMin (A, startIndex, endIndex, k);
        }
    }
	return total;
}

int main() {
    int A[50], N, Q, K;
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
        scanf ("%d", &A[i]);
    scanf ("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf ("%d", &K);
		printf ("%d\n", solve (A, N, K));
	}
	return 0;
}
