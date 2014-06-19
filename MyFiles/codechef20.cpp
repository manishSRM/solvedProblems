#include <cstdio>
#include <math.h>

#define MAX 10000

using namespace std;

int def[MAX];

int abs(int n) {
	if(n < 0)
		return -n;
	return n;
}

int total_Factors(int num) {	
	int j = 0, temp1, temp2, temp, s;
	temp = num;
	s = sqrt(num) + 1;		
	for(int i = 1; i <= s; i++) {
		if(num % i == 0) {	
			temp1 = i;
			temp2 = temp / i;
			def[j++] = abs(temp1 - temp2); 
		}
	}
	return j;
}

int lowestDiffernce(int l) {
	int temp;
    temp = def[0];
	for(int i = 1; i < l; i++) {
		if(temp > def[i])
			temp = def[i];
	}
	return temp;
}

void test_Cases(int t) {
	long long int num, length, r;
	for (int i = 0; i < t; i++) {
		scanf("%lld", &num);
		length = total_Factors(num);
		//arrayOfDifference(length);
		r = lowestDiffernce(length);
		printf("%lld\n", r);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	test_Cases(T);
	return 0;
}
