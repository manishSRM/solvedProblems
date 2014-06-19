#include <iostream>	

using namespace std;

void printArray (int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return;
}

void insertionSort (int c[], int size)  {
    int i, k, valueToInsert;
    for (i = 0; i < size - 1; i++) {
    	valueToInsert = c[i + 1];
		for (k = i; k >= 0 && c[k] > valueToInsert; k--) {	
			c[k + 1] = c[k];
		}
		c[k + 1] = valueToInsert;
   	}
    return;   
}

void copyArray (int  A[], int B[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return;
}

void merge (int A[], int m, int B[], int n, int C[]) {
    int i, j = 0, k, insert;
	copyArray (A, C, m);
        copyArray (B, C + m, n);
        printArray (C, m + n);
        insertionSort (C, m + n);
	return;
}

int main()
{
	int p, q, i, a[50], b[50], c[100];
	cin >> p;
	for (i = 0; i < p; i++)
		cin >> a[i];
	cin >> q;
	for (i = 0; i < q; i++)
		cin >> b[i];
	
	merge (a, p, b, q, c);
    	cout << "Merged array is = ";
    	printArray (c, p + q);
	return 0;
}





