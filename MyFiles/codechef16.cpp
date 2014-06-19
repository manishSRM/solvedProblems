#include<stdio.h>
#include<algorithm>

using namespace std;

void input_Array(int A[], int size) {
	for(int j = 0; j < size; j++) 
		scanf("%d", &A[j]);
}

void sort(int A[], int l) {
	int i, j;
	for(i = 0; i < l - 1; i++) {
		for(j = 0; j < l - 1 - i; j++) {
			if(A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
} 

int min_Dif(int A[], int l) {
	int temp, r;
	temp = A[1] - A[0];
	for(int i = 1; i < l - 1; i++) {
		r = A[i + 1] - A[i];		
		if(temp > r) 
			temp = r;		
	}
	return temp;
}

void test_Cases(int A[], int T) {
	int size, r;
	for(int i = 0; i < T; i++) {
		scanf("%d", &size);
		input_Array(A, size);
		sort(A, size);
		r = min_Dif(A, size);
		printf("%d\n", r);
	}
}
 
int main() {
	int t, A[5000];
	scanf("%d", &t);
	test_Cases(A, t);
	return 0;
}
