#include<stdio.h>

#define MAX 100000
#define _MAX 1000000

using namespace std;

void input_Array(int A[], long long int size) {	
	for(int j = 0; j < size; j++) 
		scanf("%d", &A[j]);
}

long long int find_Big(int A[], long long int s) {
	long long int temp = A[0], i, pos;
	for(i = 1; i < s; i++) {
		printf("a = %lld ", temp);
		if(temp >= A[i]) {
 			temp = A[i];
			pos = i;
			printf(" %lld ", temp);
		}
	}
	return temp + pos;	
}

int test_Cases(int A[], int T) {
	long long int size, big;
	for(int i = 0; i < T; i++) {
		scanf("%lld", &size);
		input_Array(A, size);
		big = find_Big(A, size);
		printf("%lld\n", big);
	}
}

int main() {
	int A[MAX], t;
	scanf("%d", &t);
	test_Cases(A, t);
	return 0;
}
