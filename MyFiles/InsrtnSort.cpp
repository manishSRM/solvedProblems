#include <iostream>

using namespace std;

void printArray (int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void InsertionSort(int A[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int valueToInsert = A [i + 1];
        for (j = i; j >= 0 && A[j] > valueToInsert; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = valueToInsert;
        printArray (A, n);
    }
    return;
}

int main()
{
    int n, A[100], i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> A[i];
    }
    InsertionSort(A, n);	
    cout << "\n";
    return 0;
}

