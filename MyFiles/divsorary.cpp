#include<iostream>
#include<stdio.h>

using namespace std;

int divisors (int num, int *divisor) {
     int i, numdivisor = 0;
     for (i = 1; i <= num; i++) {
          if (num % i == 0) {
               divisor[numdivisor] = i;
               ++numdivisor;
               printf ("divisor = %d\n", i); 
          }
     }
     printf ("value = %d\n", numdivisor);
     return (numdivisor); 
}

int main() {
     int num ,divisor[200], len;
     cin >> num;
      len = divisors (num, divisor);
      for (int i(0); i < len; i++) 
          printf ("%d\t", divisor[i]);
      printf ("\n");
      return 0;
      }
