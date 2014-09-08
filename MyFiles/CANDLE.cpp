#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

int candles[10];

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int candleNumber, minCount = INT_MAX;
		for (int i = 0; i < 10; i++)
			scanf ("%d", &candles[i]);
		for (int j = 1; j < 10; j++) {
			if (minCount > candles[j]) {
				minCount = candles[j];
				candleNumber = j;
			}
 		}
 		if (minCount > candles[0]) {
 			printf("1");
 			for (int j = 1; j <= candles[0] + 1; j++)
 				printf("0");
 			printf("\n");
 		} else {
 			for (int i = 1; i <= minCount + 1; i++) 
 				printf("%d", candleNumber);
 			printf("\n");
 		}
	}
	return 0;
}