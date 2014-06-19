#include <cstdio>

using namespace std;

int A[100];

void input_Array(int n) {
	for(int j = 0; j < n; j++) 
		scanf("%d", &A[j]);
}

int sum_Array(int l) {
	int sum = 0;
	for(int i = 0; i < l; i++) 
		sum += A[i];
	return sum;
}

int minimum(int l) {
	int temp;
    temp = A[0];
	for(int k = 1; k < l; k++) {
		if(temp > A[k])
			temp = A[k];
	}	
	return temp;
}

void minmum_NumberOfMoves(int N, int sum, int min) {
	int r;	
	r = sum - N * min;
	printf("%d\n", r);
}

void test_Cases(int T) {
	int N, sum, min;	
	for(int i = 0; i < T; i++) {
		scanf("%d", &N);
		input_Array(N);
		sum = sum_Array(N);
		min = minimum(N);
		minmum_NumberOfMoves(N, sum, min);
	}
} 

int main() {
	int T;	
	scanf("%d", &T);
	test_Cases(T);
	return 0;
}

