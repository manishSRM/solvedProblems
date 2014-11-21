#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define RAND_MAXMUM 10001

using namespace std;

int main() {
	int comNumber, guessNumber;
	srand(time(NULL));
	comNumber = rand() % RAND_MAXMUM;
	
	do {
		scanf("%d", &guessNumber);
		if(guessNumber > comNumber) {
			printf("GREATER\n");
		} else if( guessNumber < comNumber) {
			printf("LESS\n");
		}
	} while(comNumber != guessNumber);
	printf("WOW!\n");
	return 0;
} 