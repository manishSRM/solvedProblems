#include <cstdio>

using namespace std;

int A[200];

int isBitSet (int mask, int k) {
    return ((mask & (1 << k)) != 0);
}

void printSubset (int n) {
	for(int mask = 1; mask < (1 << n); mask++) {
		for(int k = 0; k < n; k++) {
			if(isBitSet(mask, k))
				printf("%d ", A[k]);
		}
		printf("\n");
	}	
}

int main () {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &A[i]);
	printSubset(n);
	return 0;
}