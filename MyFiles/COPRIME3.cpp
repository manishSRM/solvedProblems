#include <cstdio>

#define MAX 100010
#define FOR(A, B, C) for (int A = B; A < C; A++)

using namespace std;

int numArray[MAX];

int gcd(int a, int b)
{	
	if (b)
	    return gcd(b, a % b);
	return a;
}

int countCoprimeTriplet (int size) {
	if (size <= 2) 
		return 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {	
				int GCD = gcd (numArray[i], gcd (numArray[j], numArray[k]));
				if (GCD == 1) {
					//printf("%d %d %d\n", numArray[i], numArray[j], numArray[k]);
					count++;
				}
			}	
		}
	}
	return count;
}

int main () 
{
	int N;
	scanf ("%d", &N);
	FOR(i, 0, N) 
		scanf ("%d", &numArray[i]);
	printf("%d\n", countCoprimeTriplet (N));	
	return 0;
}