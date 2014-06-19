#include <stdio.h>

using namespace std;

int multiple_Five(int num) {
	int count = 0, r = 5, R;
	R = r;
	while(R <= num) {
		count += num / R;
		R *= r; 
	}
	return count;
}

void test_Cases(int t) {
	int num;
	for(int i = 1; i <= t; i++) {
		scanf("%d", &num);
		printf("%d\n", multiple_Five(num));
	}
}

int main() {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}
