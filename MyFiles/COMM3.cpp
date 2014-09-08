#include <cstdio>

using namespace std;

int distance (int a, int b, int c, int d) {
	return ((a - b) * (a - b) + (c - d) * (c - d));
}

int main () {
	int T, x1, x2, x3, y1, y2, y3, R;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &R);
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		int D1 = distance (x1, x2, y1, y2);
		int D2 = distance (x1, x3, y1, y3);
		int D3 = distance (x2, x3, y2, y3);
		if (D1 <= R * R && D2 <= R * R)
			printf("yes\n");
		else if (D2 <= R * R && D3 <= R * R)
			printf("yes\n");
		else if (D1 <= R * R && D3 <= R * R)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
