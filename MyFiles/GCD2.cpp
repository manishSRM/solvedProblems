#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

int B[260], r, k, A, size, remain, newNumber, temp, count, d;
char b[260];

void input_Array (int l) {
	for(int i = 0; b[i] != '\0'; i++) 
		B[i] = b[i] - '0';	
}	

int countdigit (int num) {
	int i = 0;
	while(num) {	
		i++;
		r = num;
		num /= 10;
	}
	return i;
}

int makeNumber (int size) {
	int num = 0;
	for (int k = 0; k < size; k++) 
		num = num * 10 + B[k];
	return num;
}

int divideNumbers (int num, int len) {
	count = countdigit (num);
	if (r > B[0])
		newNumber = makeNumber(count + 1);
	else
		newNumber = makeNumber(count);
	temp = newNumber % num;
	for(d = k; d < len; d++) {
		temp = temp * 10 + B[d];
		temp %= num;
	}
	return temp;
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %s", &A, b);
		size = strlen(b);
		input_Array(size);
		remain = divideNumbers(A, size);
		printf("%d\n", gcd(remain, A));
	}
	return 0;
}