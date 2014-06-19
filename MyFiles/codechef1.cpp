#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void magic (int t) {
	int p, k;
	long long int x, n;
	while (t--) {
		scanf ("%lld", &n);
		for (k = 0; k < n; k++) {
			scanf ("%d", &p);
		}
		x = n * (n - 1);
    	printf ("%lld", x / 2);
    	printf ("\n");
	}
}

int main() {
	int t, ans;
	scanf ("%d", &t);
	magic (t);
	return 0;    	
} 
