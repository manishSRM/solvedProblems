#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int A[N + 1];
		for(int i = 1; i <= N; i++) 
			scanf ("%d", &A[i]);
		sort(A + 1, A + N + 1);
		printf("%d\n", A[N]);
	}
	return 0;
}