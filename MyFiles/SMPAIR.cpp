#include <cstdio>
#include <algorithm>
#define MAX 100010

#define FOR(A, B, C) for (int A = B; A < C; A++)

using namespace std;

int main () 
{
	int T;
	int array[MAX];
	scanf ("%d", &T);
	while (T--) {
		int N;
		scanf ("%d", &N);
		FOR(i, 0, N) 
			scanf ("%d", &array[i]);
		sort (array, array + N);
		printf("%d\n", array[0] + array[1]);	
	}
	return 0;
}