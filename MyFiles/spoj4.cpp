#include <stdio.h>

using namespace std;

void print_Array(int A[], int n) {
	for(int i = n - 1; i >= 0; i--) 
		printf("%d", A[i]);
	printf("\n");
}

void next_Number(int A[], int a[], int len) {
	int i, j;
	i = len - 1;
	for(j = 0; j < len / 2 + 1; j++) {
		if(A[j] != A[i])
			A[j] = A[i];
		i--;				
	}
	printf("%d %d\n", A[len / 2 - 1], a[len / 2 - 1]);
	if(A[len / 2 - 1] > a[len / 2 - 1]) 
		return;
	else {
		if(len % 2 == 0)	
			A[len / 2] += 1;
		else
			A[len / 2 + 1] += 1;
	}	
}

int store_Array(int a[], int num) {
	int i = 0, rem, r;		
	while(num) {
		rem = num % 10;
		a[i++] = rem;
		num /= 10;
	}
	return i;
}

void test_Cases(int T) {
	int A[10], num, length;
	for(int i = 0; i < T; i++) {
		scanf("%d", &num);
		length = store_Array(A, num);
		next_Number(A, A, length);
		print_Array(A, length);
	} 
}

int main() {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}
