#include<stdio.h>
//#include<algorithm>

using namespace std;

int main () {
	int A[5];
	for (int i = 0; i < 5; i++) 
		scanf ("%d", &A[i]);
	for (int i = 0; i < 5; i++)
		printf ("%d\t", A[i]);
	printf ("\n");
	return 0;
}
