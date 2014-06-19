#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000

using namespace std;

void mergeSort(int arr[], int low, int mid, int high) {
    int i, m, k, l, temp[MAX];
    l = i = low;
    m = mid + 1;
    while((l <= mid) && (m <= high)) {
         if(arr[l] <= arr[m])
             temp[i] = arr[l++];
         else
             temp[i]=arr[m++];
         i++;
    }

    if(l > mid){
         for (k = m; k <= high; k++)
             temp[i++] = arr[k];
    }
    else {
         for (k = l;k <= mid; k++)
             temp[i++] = arr[k];
    }
    for ( k = low; k <= high; k++)
         arr[k] = temp[k];
}

void partition(int arr[], int low, int high) {
    int mid;
    if(low < high){
         mid = (low + high) / 2;
         partition(arr, low, mid);
         partition(arr, mid + 1, high);
         mergeSort(arr, low, mid, high);
    }
}


void input_Array(int *a, int len) {
	for(int i = 0; i < len; i++)
		scanf("%d", (a + i));
}

void output_Array(int *A, int len) {
	for(int i = 0; i < len; i++)
		printf("%d\n", *(A + i));
}

int main() {
	int size, *A;
	scanf("%d", &size);
	A = (int *)malloc(size*sizeof(int));
	input_Array(A, size);
	partition(A, 0, size - 1);
	output_Array(A, size);
	return 0;
}
