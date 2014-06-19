#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int lint;

int hcf (lint n1, lint n2) {
    int i, minimum;
     if (n1 > n2)
          
    for (i = minimum; i > 1; --i) {
        if (n1 % i == 0 && n2 % i == 0) {
            return i;
        }
    }
    return 1;
}
int main() {
     int r;
     lint num1, num2;
     printf("Enter two positive integers: "); 
     scanf("%lld %lld",&num1,&num2);
     r = hcf (num1, num2);
     printf ("Hcf of numbers is = %d\n", r);
     return 0;
}



