#include <cstdio>
#include <iostream>
#define MAX  1000000

using namespace std;

long long int array[MAX];

void initialize() {
	for(int i = 0; i < MAX; i++)
		array[i] = 0;
}

long long int calculateDollar(long long int d) {
	if(d <= 4)
		return d;
	if(d < MAX && array[d] != 0)
		return array[d];
	long long int x = calculateDollar(d / 2) + calculateDollar(d / 3) + calculateDollar(d / 4);
	if(d >= MAX)
		return max(d, x);
	array[d] = max(d, x);
	return array[d];	 
}

void american_Dollar(long long int number) {
	long long int americanDollar;
	americanDollar = calculateDollar (number);
	printf("%lld\n", americanDollar);
}
 
int main () {
	long long int num;
	initialize();
	while(scanf("%lld", &num) != EOF)
		american_Dollar(num);
	return 0;
}