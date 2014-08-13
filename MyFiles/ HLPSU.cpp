#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

const K = 25;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N;
		scanf ("%d", &N);
		vector <bool> prime (N + 1, true);
		for(int i = 2; i <= MAX / i; i++) {
   		    for(int j = i * i; j <= MAX; j += i) {
        	    prime[j] = false;
       		}
    	}
    	int maxSum = 0;
    	for (int k = 29; k <= N; k++) {
    		if (prime[k] == true)
    			maxSum += k;
    	}
    	printf("%d\n", maxSum);
	}
	return 0;
}