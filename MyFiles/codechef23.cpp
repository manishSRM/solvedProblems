#include <cstdio>

using namespace std;

long long int A[100000];

void input_Array(int l) {
	for (int i = 0; i < l; i++)
		scanf("%lld", &A[i]);
	return;
}

long long int maximum_NumberInArray (int N) {
	long long int temp;
	temp = A[0];
	for(int i = 1; i < N; i++) {
		if(temp < A[i])
			temp = A[i];
	}
	return temp;
}

void travel(int l, long long int max) {
	for (int i  = 0; i < l; i++) {
		A[i] = max - A[i];
	}
	return;
}

void test_Cases(int N, long long int K) {
	long long int max;
	int last = 0;
	if(K != 0) {
		if(K % 2 == 0) 
			last = 2;
		else
			last = 1;
	}	
	for(int j = 1; j <= last; j++) {
		max = maximum_NumberInArray(N);
		travel(N, max);
	}
	return;
}

void print_Array(int l) {
	for(int j = 0; j < l; j++) 
		printf("%lld ", A[j]);
	printf("\n");
}

int main() {
	int N;
	long long int K;
	scanf("%d %lld", &N, &K);
	input_Array(N);
	test_Cases(N, K);
	print_Array(N);
	return 0;
}