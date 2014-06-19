#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;
void searchTriplet () {
	int i, j, k;	
	int count = 0, loop = 0;	
	for (k = 102; k <= 1000; k++) {
	        for (j = 100; j < k; j++)  {
			loop++;
			i = sqrt (k * k - j * j);
               	 	if (i * i + j * j == k * k && i >= 100 && i < j) {
                    	printf ("%d %d %d\n", i, j, k);
                	count++;
            }
        }
    }
	printf ("Numbedr of loop: %d\n", loop);	
	printf ("number of triplets: %d\n", count);
    return;

}

int main() {
    cout << "Pythagorean triplet = \n";
    searchTriplet ();
    return 0;
}

