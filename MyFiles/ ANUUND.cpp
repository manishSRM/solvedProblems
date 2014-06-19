#include <cstdio>
//#include <algorithm.h>
#define MAX 100000

using namespace std;

long long int array[MAX];
long long int array2[MAX];

void inputArray(int  size) {
    for(int j = 0; j < size; j++) 
        scanf("%lld", &array[j]);
}

void mergeSort(long long int arr[], int low, int mid, int high) {
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

void partition(long long int arr[], int low, int high) {
    int mid;
    if(low < high){
         mid = (low + high) / 2;
         partition(arr, low, mid);
         partition(arr, mid + 1, high);
         mergeSort(arr, low, mid, high);
    }
}

void printArray(int l) {
    for(int i = 0; i < l; i++)
        printf("%lld ", array2[i]);
    printf("\n");
}

void finalArray(int n) {
    int m = 0, l;
    l = n - 1; 
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
            array2[i] = array[m++];
        else
            array2[i] = array[l--];
    }
}

void testCases(int T) {
    for(int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        inputArray(n);
        partition(array, 0, n - 1);
        //sort(array[1], array[n]);
        finalArray(n);
        printArray(n);
    }
} 

int main() {
    int t;
    scanf("%d", &t);
    testCases(t);
    return 0;
}   