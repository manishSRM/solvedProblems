#include <stdio.h>

using namespace std;

void binaryForm(int num) {
	int a[50], i = 0, c;
	while(num > 0) {
		c = num % 2;
		a[i++] = c;
		num /= 2; 
	}
	for(int j = i - 1; j >= 0;  j--) 
		printf("%d ", a[j]);
	printf("\n");
	return;
}

int main() {
	int num;
	scanf("%d", &num);
	binaryForm (num);
	return 0;
}
