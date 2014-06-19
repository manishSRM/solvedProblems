#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int lint;

lint gcd (lint n1, lint n2) {
    if (n1 < n2)
        swap (n1, n2);
    while (n2) {
        lint r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    return n1;
}

lint lcm (lint n1, lint n2) {
    lint g_c_d = gcd (n1, n2);
    lint result;
    result = n1 / g_c_d;
    return (result * n2);
}

int main() {
     lint num1, num2, r;
     printf("Enter two positive integers: "); 
     scanf("%lld %lld",&num1,&num2);
     r = lcm (num1, num2);
     printf ("LCM of numbers is = %lld\n", r);
     return 0;
}
