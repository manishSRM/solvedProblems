#include <iostream>

using namespace std;

void printArray (int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return;
}

void copyArray (int A[], int B[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        B[i] = A[i];
    }
}

void merge (int A[], int m, int B[], int n, int C[]) {
    int i, j, k;
    for (i = j = k = 0; i < m && j < n;) {
        if (A[i] > B[j])
            C[k++] = B[j++];
        else
            C[k++] = A[i++];
    }
    if (j < n)
        copyArray (B + j, C + k, n - j);
    if (i < m)
        copyArray (A + i, C + k, m - i);
        
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
