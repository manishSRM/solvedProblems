#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T) {
		int A[T], B[T];
		for (int i = 1; i <= T; i++)
			scanf ("%d", &A[i]);
		for (int j = 1; j <= T; j++) 
			B[A[j]] = j;
		int flag = 0;
		for (int k = 1; k <= T; k++) {
			if (B[k] != A[k]) {
				flag = 1;
				break;
			}
		}
		if (!flag) 
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		scanf ("%d", &T);
	}
	return 0;
}