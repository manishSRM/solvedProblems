#include <cstdio>
#include <iostream>

using namespace std;

void testCases (int T) {
	for(int i = 0; i < T; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int Big = max(a, b);
		printf("%d %d\n", Big, a + b);
	}
}

int main() {
	int t;
	scanf ("%d", &t);
	testCases(t);
	return 0;
}