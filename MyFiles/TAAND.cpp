#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main () {
	int N, temp = INT_MIN, max = INT_MIN;
	int A[5001];
	scanf ("%d", &N);
	for (int k = 0; k < N; k++) 
		scanf ("%d", &A[k]);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int r = A[i] & A[j];
			if (temp < r) 
				temp = r;
		}
		if (max < temp)
		 	max = temp;
	}
	printf("%d\n", max);
	return 0;
}