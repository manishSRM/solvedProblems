#include <cstdio>

using namespace std;

void firstCase(int num) {
	if(360 % num == 0)
		printf("y ");
	else
		printf("n ");
}
 
void secondCase(int num) {
	if(num <= 360)
		printf("y ");
	else
		printf("n ");
}

void thirdCase(int num) {
	int temp, n;
	if (num > 360) {
		printf("n\n");
		return;
	}	
	n = num - 1;
	temp = 360 - n*(n + 1) / 2;
	if (temp > num)
		printf("y\n");
	else
		printf("n\n");
}

void testCases(int T) {
	for(int i = 0; i < T; i++) {
		int num;
		scanf("%d", &num);
		firstCase(num);
		secondCase(num);
		thirdCase(num);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}