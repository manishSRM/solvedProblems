#include<stdio.h>

using namespace std;

int min_diff(int a[], int t) {
	int j = -1, d, min = 20 ;	
		d = a[++j] - a[j];
		if (d<min)
			min=d;
	return min;				
}

int main() {
	int A[] = {2, 4, 7, 9, 18, 19}, r;
	r = min_diff(A, 6);
	printf("%d\n", r);
	return 0;
}
