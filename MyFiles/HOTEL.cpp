#include <cstdio>

using namespace std;

int arrival[100];
int departure[100];
int storeMaxCount[100];

void initializeArrays1(int l) {
	for(int i = 0; i < l; i++) 
		scanf("%d", &arrival[i]);
	for(int j = 0; j < l; j++) 
		scanf("%d", &departure[j]);
}

void countMans(int length) {
	int count = 0, max_count = 0, c = 0, d = 0;
	for(int k = 0; k < length; k++) {
		if(arrival[k] < departure[c]) 	
			count++;
		else if(arrival[k] == departure[c])
			c++;
		else {
			c++;
			count--;
		}	
		max_count += count;
		storeMaxCount[d++] = max_count;
		count = 0;							
	}
}

void print(int l) {
	for(int i = 0; i < l; i++)
		printf("%d ", storeMaxCount[i]);
	printf("\n");
}

void mergeSort(int arr[], int low, int mid, int high) {
    int i, m, k, l, temp[100];
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

int findMax(int l) {
	int temp = storeMaxCount[0];
	for(int v = 0; v < l; v++) {
		if(temp < storeMaxCount[v])
			temp = storeMaxCount[v];
	}
	return temp; 		 
}

void testCases(int T) {
	for(int a = 0; a < T; a++) {
		int len, count;
		scanf("%d", &len);
		initializeArrays1(len);
		partition(arrival, 0, len - 1);
		partition(departure, 0, len - 1);
		countMans(len);
		count = findMax(len);
		print(len);
		printf("%d\n", count);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}