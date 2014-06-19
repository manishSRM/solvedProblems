#include<stdio.h>

#define MAX 100000
#define _MAX 1000000

using namespace std;

long long int total_Pairs(int A[], long long int n) {
	long long int m, x, y, s;
	m = A[1];
	x = A[2];
	y = A[0];
	s = y*n - y*(y+1)/2;	
	return n*(n-1)/2 - m*n + m*(m+1)/2 - x*(x - 1)/ 2 - s + m*y; 
}

void input_Array(int A[], int size) {	
	for (int i = 0; i < size; i++) 	
		scanf("%d", &A[i]);	
}

void test_Cases(int A[], int t) {
	int B[3];
	long long int size;
	for (int i = 0; i < t; i++) {
		scanf("%lld", &size);
		input_Array(A, size);
		for (int j = 0; j < 3; j++) 
			B[j] = 0;
		for (int i = 0; i < size; i++) {
			if(A[i] < 3)			
				B[A[i]]++;
		}
		printf("%lld\n", total_Pairs(B, size));
	}
}

int main() {
	int t, A[MAX];
	scanf("%d", &t);
	test_Cases(A ,t);
	return 0;
}
