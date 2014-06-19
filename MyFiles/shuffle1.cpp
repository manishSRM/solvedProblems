#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

void printArray (int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return;
}

void shuffle (int A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		swap (A[i], A[rand () % n]);
	}
	return;	
}
int main() {
	int a[50], i, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	shuffle (a, n);
	printArray (a, n);
	return 0;
} 
