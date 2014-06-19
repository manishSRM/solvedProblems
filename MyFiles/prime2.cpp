#include<iostream>
#include<stdio.h>

typedef long long int lint;

using namespace std;
                                                  // return 1 when number is prime otherwise 0
int isPrime (lint num) {
    lint i;
    if (num == 1) 
        return 0;    
    for (i = 2; i <= num / i; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    int r, c;
    lint num;
    scanf ("%d", &c);
    while (c--) {
        scanf ("%lld", &num);
        r = isPrime (num);
        printf ("Result = %d \n", r);
    }
    return 0;
}

