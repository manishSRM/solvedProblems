#include<stdio.h>

using namespace std;

void result(int num, float current) {	
	if(num % 5 == 0 && num < current) 
		printf("%0.2f\n", current - num - 0.50);
	else
		printf("%0.2f\n", current);
}

int main() {
	int num;
	float balance, current;
	scanf("%d %f", &num, &current);
	result(num, current);
	return 0;
}
