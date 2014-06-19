#include <cstdio>
#include <iostream>
#define MAX 100000 

using namespace std;

int array[MAX];

void initalizeArray (int l) {
	for(int i = 0; i < l; i++) 
		scanf("%d", &array[i]);
}

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int checkFactor(int f) {
	for(int i = 2; i <= f / i; i++) {
		if(f % i == 0)
			return i;
	}
	return f;
}

int smallestDivisor (int length) {
	int finalGcd = array[0];
	for(int i = 1; i < length; i++) {
		finalGcd = gcd(finalGcd, array[i]);
	}
	if(finalGcd == 1)
		return -1;
	finalGcd = checkFactor(finalGcd);
	return finalGcd;
}

void testCases (int T) {
	for(int i = 0; i < T; i++) {
		int size;
		scanf ("%d", &size);
		initalizeArray(size);
		printf("%d\n", smallestDivisor(size));
	}
}

int main () {	
	int t;
	scanf("%d", &t);
	testCases(t); 
	return 0;
} 