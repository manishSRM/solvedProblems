#include <cstdio>

using namespace std;

void check_Num(long long int num) {
	int rem;
	rem = num % 6;
	if(rem == 0 || rem == 1 || rem == 3)
		printf("yes\n");
	else
		printf("no\n");
}

int main() {
	long long int num;
	scanf("%lld", &num);
	check_Num(num);
	return 0;
}