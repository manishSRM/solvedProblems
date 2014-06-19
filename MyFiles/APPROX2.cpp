#include <cstdio>
#include <limits.h>
#define MAX 1000

using namespace std;

long long int A[MAX];
long long int K;  

void initalizeArray (int l) {
	for(int i = 0; i < l; i++) 
		scanf ("%lld", &A[i]);
}

long long int absolute (long long int x) {
	if(x > 0)
		return x;
	return -x; 
}

int countPairs (int l) {
	int count = 0; 
	long long int min = INT_MAX, temp;
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			if(i == j)
				continue;
			temp = absolute(A[i] + A[j] - K);
			if (min >= temp) {
			    if(temp == min) 
				    count++;
			    else {
			        min = temp;
			        count = 1;
			    }
			}    
		}
	}
	printf("%lld", min);
	return count / 2;
}

void testCases (int T) {
	for (int i = 0; i < T; i++) {
		int size;
		scanf("%d %lld", &size, &K);
		initalizeArray(size);
		printf(" %d\n", countPairs(size));
	}
}

int main () {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}