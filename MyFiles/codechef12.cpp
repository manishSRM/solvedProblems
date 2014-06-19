#include<stdio.h>

using namespace std;

void input_Array(int A[], int size) {
	for(int i = 1; i <= size; i++) 
		scanf("%d", &A[i]);
}

void X(int B[]) {
	for(int i = 1; i <= 10000; i++) 
		B[i] = 0;
}

int MAXCOUNT(int A[], int B[], int l) {
	int temp, pos;
	X(B);
	for(int i = 1; i <= l; i++) 
		B[A[i]]++;
	temp = B[1];
	pos = 1;
	for(int j = 2; j <= 10000; j++)
		if(temp < B[j]) {
			temp = B[j];
			pos = j;
	}
	printf("%d", pos);
	return 	temp;
}

void test_Cases(int A[], int B[], int T) {	
	int size, pos, r;
	for(int i = 1; i <= T; i++) {
		scanf("%d", &size);
		input_Array(A, size);
		r = MAXCOUNT(A, B, size);
		printf(" %d\n", r);
	}
}

int main() {
	int A[101], B[10001], t;
	scanf("%d", &t);
	test_Cases(A, B, t);
	return 0;
}
