#include <cstdio>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

int main () {
	int comAddr[4];
	int mask[4];
	int netAddr[4];
	uint32_t comAd = 0;
	uint32_t mask32 = 0;
	uint32_t netAd = 0;
	int prefix;
	scanf("%d%*c%d%*c%d%*c%d", &comAddr[3], &comAddr[2], &comAddr[1], &comAddr[0]);
	scanf("%d", &prefix);
	for(int i = 3; i >= 0; i--) 
		comAd = comAd * 256 + comAddr[i];
	for(int j = 32 - prefix; j < 32; j++) 
		mask32 = mask32 | (1 << j);
	netAd = comAd & mask32;
	for(int i = 0; i < 4; i++) {
		mask[i] = mask32 % 256;
		mask32 = mask32 / 256;
	}
	for(int i = 0; i < 4; i++) {
		netAddr[i] = netAd % 256;
		netAd = netAd / 256;
	}
	printf("COMPUTER ADDRESS : ");
	printf("%d.%d.%d.%d\n", comAddr[3], comAddr[2], comAddr[1], comAddr[0]);
	printf("MASK : "); 
	printf("%d.%d.%d.%d\n", mask[3], mask[2], mask[1], mask[0]);
	printf("NET ADDRESS : ");
	printf("%d.%d.%d.%d\n", netAddr[3], netAddr[2], netAddr[1], netAddr[0]); 
 	return 0;
}