#include<stdio.h>

using namespace std;

int min (int A, int B) {
    if (A < B) return A;
    return B;
}

int commonCount (int A[], int n1, int B[], int n2) {
    int countA[101], countB[101];
    for (int i = 0; i <= 100; i++) {
        countA[i] = 0;
		countB[i] = 0;
	}
    for (int i = 0; i < n1; i++)
        countA[A[i]]++;
    for (int i = 0; i < n2; i++)
        countB[B[i]]++;

    int total = 0;
    for (int i = 0; i <= 100; i++)
        total += min (countA[i], countB[i]);
    return total;
}

int main () {
	int A[] = {2, 3, 0, 8, 6, 4, 9}, B[] = {8, 9, 0, 1, 6, 5, 3}, m, n, r;
	m = n = 7;
	r = commonCount (A, m, B, n);
	printf ("\n%d\n", r);
	return 0;
}

