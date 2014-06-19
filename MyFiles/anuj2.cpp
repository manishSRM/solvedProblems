#include <stdio.h>
#include <algorithm>

using namespace std;

void bubsort(int A[], int n) {
	int c = 0, j, i, k = 0;
	for(j = 0; j > -1; j++) {
		for(i = 0; i < n; i++) {
			if(A[i] > A[i+1]) {
				swap(A[i+1], A[i]);
			}
			else
				c = ++k;		
		}
		if(c == n)
			break;
		else
			c = 0;
		k = 0; 
	}
}

int main() {
	int a[] = {5, 3, 1, 6, 0, 2}, n = 6;
	bubsort(a, n);
	for(int i = 0; i < 6; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
