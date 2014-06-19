#include <stdio.h>

using namespace std;

void printArray(int A[], int n) {
	for (int i = n - 1; i >= 0; i--)
		printf("%d", A[i]);
	printf("\n");
}

void factorial(int num) {
	int value, A[200], n = 1, r = 0;
	A[0] = 1;
	while(num) {
		for(int j = 0; j < n; j++) {
			value = (A[j] * num) + r;
			r = value / 10;
			A[j] = value % 10;
		}
		while(r) {
			A[n++] = r % 10;
			r /= 10;
		}
		num--;     
	}
	printArray(A, n);
}

void test_Cases(int t) {
	int n;
	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		factorial(n);
	} 
}

int main() {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}
