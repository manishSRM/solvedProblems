#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int lint;

int armstrongNumber (int num) {
     int r, sum = 0;
     int n = num;
     while (num) {
          r = num % 10;
          num /= 10;
          sum = sum + (r*r*r);
     }
     if (sum == n) 
         return 1;
     else 
          return 0;
    return 0;           
}
int main(){
     int num;
     int r;
     scanf ("%d", &num);
     r = armstrongNumber (num);
     if (r == 1)
          printf ("The number is an armstrong number\n");
     else
          printf ("The number not is an armstrong number\n");
     return 0;          
}
