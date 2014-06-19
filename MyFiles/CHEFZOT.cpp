#include <cstdio>
#define MAX 100000

using namespace std;

int A[MAX];

int findMaxLength (int A[], int size) {
	int maxlen = 0, len = 0;
	for (int i = 0; i < size; i++) {
		if(A[i] != 0) 
			len++;
		else 
			len = 0;
		if (maxlen < len)
			maxlen = len;
	}
	return maxlen;
}

int main () {
	int size;
	scanf ("%d", &size);
	for (int i = 0; i < size; i++) 
		scanf ("%d", &A[i]);
	printf("%d\n", findMaxLength (A, size));
	return 0;
}