
#include <cstdio>

using namespace std;

int countDistinctPrime (int num) {
	int count = 0;
	for (int i = 2; i <= num / i; i++) {
		if (num % i == 0) {
			count++;
			do {
			    num /= i;
			} while (num % i == 0);
		}
	}
	if (num > 1) {
	    count++;
	}
	return count;
}

int main () {
	int N; 
	scanf ("%d", &N);
	printf("%d\n", countDistinctPrime (N));
	return 0;
}