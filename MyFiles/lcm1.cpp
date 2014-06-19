#include<iostream>
#include<stdio.h>

using namespace std;


int lcm (int n1, int n2) {
    int big = max (n1, n2);
    while(1) {
        if (big % n1 == 0 && big % n2 == 0)
            break;
    ++big;
    }
    return big;
}

int main() {
     int num1, num2, r;
     printf("Enter two positive integers: "); 
     scanf("%d %d",&num1,&num2);
     r = lcm (num1, num2);
     printf ("LCM of numbers is = %d\n", r);
     return 0;
}

