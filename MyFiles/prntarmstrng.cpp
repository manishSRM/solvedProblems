#include<iostream>
#include<stdio.h>

using namespace std;

#define ss(num) scanf("%lld", &num); 
typedef long long int lint;

int checkArmstrongNumber (lint num) {
    lint r, sum = 0, n;
    n = num;
    while (num) {
        r = num % 10;
        num /= 10;
        sum = sum + (r * r * r);
    }
    if (sum == n)
        return 1;
    return 0;
}

lint printArmstrongNumber(lint num, int AR[]) {
    lint i;
    int len = 0;
    for (i = 1; i <= num; i++) {
        if (checkArmstrongNumber (i))
            AR[len++] = i;
    }    
    return len;      
} 
int main() {
     lint num;
     int ar[200], anum;
     ss (num)
     anum = printArmstrongNumber (num, ar);
     if (anum == 0)
        printf ("No number found\n");
     else {
        printf ("Armstrong number = \n");
        for (int i = 0; i < anum; i++) 
            printf ("%d\t", ar[i]);   
     }
     printf ("\n");
     return 0;
}
