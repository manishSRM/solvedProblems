#include<iostream>
#include<stdio.h>

using namespace std;

int pt[1000000];

void marbles (int n, int q) {
	int i, j, sum = 0;
	char ch2;
	for (int c = 0; c < n; c++) 
		scanf ("%d", (pt  + c));
	for (int r = 0; r < q; r++) {
		scanf ("\n%c %d %d", &ch2, &i, &j);
		if (ch2 == 'S') {
			while (i <= j) 
				sum += pt[i++];
			printf ("%d\n", sum);
			sum = 0;
		}
		else if(ch2 == 'G') 	
			pt[i] += j;
		else
			pt[i] -= j;
	}
}

int main() {
	int n, q;
	scanf ("%d %d", &n, &q);
	marbles (n, q);
	return 0;
}

