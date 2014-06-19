#include<iostream>
#include<stdio.h>

using namespace std;
int factorial (int num) {
    int fact = 1;					// x - x^2 / 2! + x^4 / 4! - x^6 / 6!........
	while (num) {	
		fact *= num;
		--num; 
	}									 
	return (fact);
}
int power (int num, int p) {
	double ans = 1;
	for (int i = 0; i < p; i++) {	
		ans = ans * num;
	}
	return (ans);
}
double sumOfSeries (int x,int n) {
	int i, j, sign = 1, f, k = 0;
	double pr;
	float sum = 0;
	for (i = j = 0; i < n; i++, j += 2) {	
		if (i == 0)  {
			sum += x;
			f = factorial (j);
    			pr = power (x, j);
		}	
		else {
		   f *= (j * (j - 1));  
		   pr *= x * x;
	           sum += (pr / f) * sign;
		   k = f;	
		}
    	sign *= -1;
	}
	return (sum); 
}
int main() {
	int x, n;
	float result;
	cin >> x >> n;
	result = sumOfSeries (x, n);
	printf ("Sum of series = %f\n", result);
	return 0;
}
