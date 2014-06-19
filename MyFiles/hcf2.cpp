#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int lint;

lint gcd (lint n1, lint n2) {
    lint r = 0;
    if (n1 < n2)
      swap (n1, n2);
    if (n2 == 0)
        return n1;
    r = n1 % n2;
    while (r) {
      n1 = n2;
      n2 = r;
      r = n1 % n2;
    }
    return n2;
}

int main() {
     lint r;
     lint num1, num2; 
     printf("Enter two positive integers: "); 
     scanf("%lld %lld",&num1,&num2);
     r = gcd (num1, num2);
     printf ("Hcf of numbers is = %lld\n", r);
     return 0;
}

