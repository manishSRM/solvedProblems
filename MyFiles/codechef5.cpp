#include<stdio.h>
#include<math.h>

using namespace std;

int is_Prime(int num) {
	int i, squrt;
	if (num == 1)
		return 0;
	squrt = sqrt(num) + 1;
	for(i = 2; i <= squrt; i++) {
		if(num % i == 0)
			return 1;
	}
	return 0;
}

int next_Prime( int sum) {
	int r;	
	while(1) {
		sum++;
		r = is_Prime(sum);
		if(r == 0) 
			break;
	}
	return sum;
}

void test_Cases(int T) {
	int x, y, result;
	for(int j = 1; j <= T; j++) {
		scanf("%d %d", &x, &y);
		result = next_Prime(x + y);
		printf("%d\n", result - (x + y)); 
	}
} 

int main() {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}

