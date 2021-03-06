#include <iostream>
#include <stdio.h>

using namespace std;

void merge(int *a, int *b, int low, int mid, int high) {
    int h, i, j, k;
    h = i = low;                                                
    j = mid + 1;
    while((h <= mid) && (j <= high)) {
        if(a[h] <= a[j]) 
            b[i]=a[h++];
        else
            b[i]=a[j++];
        i++;
    }
    if(h > mid) {
        for(k = j; k <= high; k++)
            b[i++] = a[k];
    }
    else {
        for(k = h; k <= mid; k++)
            b[i++] = a[k];
    }
    for(k = low; k <= high; k++) 
        a[k] = b[k];
}

void mergesort(int *a, int*b, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, b, low, mid);
        mergesort(a, b, mid + 1, high);
        merge(a, b, low, mid, high);
    }
}
 
int main() {
    int a[] = {12, 10, 43, 23, -78, 45, 123, 56, 98, 41, 90, 24};
    int N = sizeof(a)/sizeof(int);
    int b[N];
    mergesort(a, b, 0, N-1);
    for(int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}