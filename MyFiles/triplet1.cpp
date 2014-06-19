#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;
void searchTriplet () {
	int i, j, k, count = 0, loop = 0;
	loop = 0;
	for (i = 100; i <= 1000; i++) {
	    for (j = i + 1; j <= 1000; j++) {
	        loop ++;
	        k = sqrt(i * i + j * j);
	        if (k * k == i * i + j * j && k <= 1000) {
	            printf ("%d %d %d\n", i, j, k);
	            count++;
	        }
	    }
	}
	printf ("Number of loop = %d\n", loop);
	printf ("Number of triplet = %d\n", count);
    return;
}

int main() {
    cout << "Pythagorean triplet = ";
    searchTriplet ();
    return 0;
}

