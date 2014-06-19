#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int calulateLength (int x1, int y1, int x2, int y2) {
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) *  (y1 - y2));
}

int checkTriangle (int A, int B, int C) {
	if (A > B)
		swap (A, B);
	if (B > C)
		swap (B, C);
	if ( C == A + B)
		return 1;
	return 0;
}

int main () {
	int N, count = 0;
	scanf ("%d", &N);
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2, x3, y3;
		scanf ("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		int a = calulateLength (x1, y1, x2, y2);
		int b = calulateLength (x2, y2, x3, y3);
		int c = calulateLength (x3, y3, x1, y1);
		count += checkTriangle (a, b, c); 
	}
	printf("%d\n", count);
	return 0;
}