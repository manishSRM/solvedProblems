#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lln;

int main () {
	int x, N;
	lln sum = 0;
	scanf ("%d", &N);
	lln seriesSum = (lln)N * (lln)(N + 1) / 2;
	for (int i = 1; i <= N; i++) {
		scanf ("%d", &x);
		sum += x;
	}	
	if (seriesSum == sum) 
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}