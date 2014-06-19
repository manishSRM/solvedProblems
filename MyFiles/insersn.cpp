#include <iostream>
#include <stdio.h>

using namespace std;

void Insertion (int ar[], int n, int num, int index)  {
	int i, j;
	for (i = n; i > index; --i) {
		ar[i] = ar[i - 1];
	}
	ar[i] = num;	
	for (j = 0; j <= n; ++j)
		cout << ar[j] << " ";

	return;
}

int findIndex (int B[], int length, int number) {
	for (int j = 0; j < length - 1; j++) {
		printf("%d ", j);
		if ((B[j] <= number) && (number <= B[j + 1])) {
			return j + 1;			
		}	
	}
	if (B[0] >= number)
		return 0;
	return length;
}

int main()
{	
	int  A[100], num, size;
	scanf ("%d", &size);
	for (int i = 0; i < size; i++) 
		scanf ("%d", &A[i]);
	scanf ("%d", &num);
	int index = findIndex (A, size, num);
	cout << "\n";
	Insertion (A, size, num, index);
	cout << "\n";
	return 0;
}
