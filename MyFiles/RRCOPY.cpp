#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N;
		scanf ("%d", &N);
		vector <int> V(N + 1);
		for (int i = 1; i <= N; i++)
			scanf ("%d", &V[i]);
		vector <bool> check (N + 1, false);
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (check[V[j]] == false) {
				count++;
				check[V[j]] = true;
			}	
		}
		printf("%d\n", count);
	}
	return 0;
}