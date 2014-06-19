#include <cstdio>
#include <math.h>
#define MAX 100000

using namespace std;

int array[MAX];

void initializeArray (int l) {
	for(int i = 0; i < l; i++) 
		scanf("%d", &array[i]);
}

int find_max (int l) {
	int Big = array[0];
	for (int i = 1; i < l; i++) {
		if(Big < array[i])
			Big = array[i];
	}
	return Big;
}
                                                  
int checkPrime (int num) {
    int i;                              
    if (num == 1)                                 
           return 0;                                                           
    for (i = 2; i <= (num / i); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int smallestDivisor (int length) {
	int max = find_max(length);
	int flag1;
	for(int k = 0; k < length; k++) {
		flag1 = 1;
		if(max != array[k]) {
			flag1 = 0;
			break;	 
		}	
	}

	if(flag1 == 1 && checkPrime(max))
		return max;
	
	for(int c = 2; c <= max / 2; c++) {
	    int flag = 1;
		for(int p = 0; p < length; p++) {
			if(array[p] % c != 0) {
				flag = 0;
				break;
			}	
		}
		if(flag == 1)
			return c;
	}
	return -1;
}

void testCases (int T) {
	for(int i = 0; i < T; i++) {
		int size;
		scanf("%d", &size);
		initializeArray(size);
		printf("%d\n", smallestDivisor(size));
	}
}

int main () {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}