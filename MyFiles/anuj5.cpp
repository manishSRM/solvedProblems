#include <stdio.h>

using namespace std;

int storeInArray(int a, int arr[]) {
	int i = 0, r;
	while(a) {
		r = a % 10;
		a /= 10;
		arr[i++] = r;
	}
	return i - 1;
}

void print_Array(int a[], int j) {
	for(int i = j; i >= 0 ; i--)
		printf("%d",a[i]);
	printf("\n");	
}

int main() {
	int arr[200], a, j, i; 
	scanf("%d",&a);
	j = storeInArray(a, arr);
	print_Array(arr, j);
	return 0;
}
