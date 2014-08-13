#include <cstdio>

using namespace std;

int main () {
	int menus[12] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
	int T, P;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &P);
		int minMenu = 0;
		for (int i = 0; i < 12; i++) {
			if (P >= menus[i]) {
				do {
					P -=menus[i];
					minMenu++; 
				} while (P >= menus[i] && P != 0);
			}
			if (P == 0) 
				break;
		}
		printf("%d\n", minMenu);
	}
	return 0;
}