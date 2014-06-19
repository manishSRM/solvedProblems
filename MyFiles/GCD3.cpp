#include <cstdio>
#include <iostream>

using namespace std;

int divideNumbers (char b[], int num) {
	int rem = 0;
	for(int d = 0; b[d] != '\0'; d++) {
	    int nextDigit = b[d] - '0';
		rem = (rem * 10 + nextDigit) % num;
	}
	return rem;
}

int gcd(int a, int b)
{	
	if (b)
	    return gcd(b, a % b);
	return a;
}

int main () {
	int t, A, B;
	char b[260];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &A, b);
		if(A == 0) {
			printf("%s\n", b);
			continue;
		}	
		B = divideNumbers(b, A);
		printf("%d\n", gcd(A, B));
	}
	return 0;
}