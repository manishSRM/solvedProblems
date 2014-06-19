#include <stdio.h>

using namespace std;

void printSubArray (int A[], int startIndex, int endIndex) {
    for (int i = startIndex; i <= endIndex; i++) {
        printf ("%d ", A[i]);
    }
    printf ("\n");
}

void printAllSubArrays (int A[], int n) {
    for (int startIndex = 0; startIndex < n; startIndex++) {
        for (int endIndex = startIndex; endIndex < n; endIndex++) {
            printSubArray (A, startIndex, endIndex);
        }        
    }
}

int main() {
    int A[50], n;
    scanf ("%d\n", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &A[i]);
    printAllSubArrays (A, n);    
	return 0;
}

