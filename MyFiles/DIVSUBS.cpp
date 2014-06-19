#include <cstdio>
#define MAX 100000

using namespace std;

long long int A[MAX];

void initalizeArray (int l) {
	for(int i = 0; i < l; i++) 
		scanf ("%lld", &A[i]);
}

int isBitSet (int mask, int k) {
    return ((mask & (1 << k)) != 0);
}

int finSubset (int size) {
	for(int mask = 1; mask < (1 << size); mask++) {
		long long int sum = 0;
		int countLen = 0;
		for(int k = 0; k < size; k++) {
			if(isBitSet(mask , k)) {
				sum += A[k];
				countLen++;
			}
		}
		if(sum % size == 0) {
			printf("%d\n", countLen);
		return mask;
		}
	}
	printf("-1\n");
	return -1;
}

void printIndices (int mask, int size) {
	for(int i = 0; i < size; i++) {
		if(isBitSet(mask, i))
			printf("%d ", i + 1);
	}
	printf("\n");
}

void testCases (int T) {
	for (int i = 0; i < T; i++) {
		int size, indices;
		scanf("%d", &size);
		initalizeArray(size);
		indices = finSubset (size);
		if(indices != -1)
			printIndices(indices, size);
	}
}

int main () {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}