#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void vladsongs (int t) {
	int n, k, *pt, num;
	int c = 1;
	while (t--) {
		scanf ("%d", &n);
		pt = (int *)malloc(n*sizeof(int));
		for (int i = 0; i < n; i ++) {	
			scanf ("%d", (pt + i));
		}
		//printf ("Enter tne intdex\n");
		scanf ("%d", &k);
		num = *(pt + k - 1);
		for (int j = 0; j < n; j ++) {	
			if (num > *(pt + j))
				c++;
		}
	    printf ("%d", c);
		printf ("\n");
		c = 1;	
	}
}

int main() {
	int t;
	scanf ("%d", &t);
	vladsongs(t);
	return 0;
}

