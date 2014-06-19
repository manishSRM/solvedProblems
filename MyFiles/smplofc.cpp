#include<iostream>
#include<stdio.h>

using namespace std;

int main () {
    int n1, *iptr;
    char ch = 'a', *cptr;
    double doubl, *pdub;
    iptr = &n1;
    cptr = &ch;
    pdub = &doubl;
    printf ("\n%p, %p, %p \n \n", iptr, cptr, pdub);
    return 0;    
}

