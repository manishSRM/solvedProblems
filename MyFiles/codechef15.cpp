#include<stdio.h>
#include<algorithm>

using namespace std;

void input_Array(int A[], int l) {
	for(int i = 0; i < l; i++)
		scanf("%d", &A[i]);
}

void sort(int ar[], int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < (n - 1 - i); ++j) {
            if (ar[j] > ar[j + 1]) 
                swap (ar[j], ar[j + 1]);
        }
	}
	return;
}

int count_Pies(int A[], int B[], int l) {
	int count = 0, i, j, x = 0;
	for(i = 0; i < l; i++) {
		for(j = x; j < l; j++) {	
			if(A[i] <= B[j]) {
				count++;
				x = j + 1;
		        break;
			}
		}
	}
	return count;
}

void test_Cases(int A[], int B[], int T) {
	int size, r;	
	for(int i = 0; i < T; i++) {
		scanf("%d", &size);
		input_Array(A, size);	
		input_Array(B, size);
		sort(A, size);	
		sort(B, size);
		r = count_Pies(A, B, size);
		printf("%d\n", r);
	}
}

int main() {
	int A[30], B[30], t;
	scanf("%d", &t);
	test_Cases(A, B, t);
	return 0;
}
