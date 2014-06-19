#include<iostream>
#include<stdio.h>

using namespace std;

struct Complex {
    int real;
    int imaginary;
};
void input (Complex *a) {
    scanf ("%d", &a -> real);
    scanf ("%d", &a -> imaginary);
}

void output (Complex &b) {
    printf ("%d + i%d\n", b.real, b.imaginary);
}
/*
void complexAdd (const Complex &a, const Complex &b, Complex *p) {
    p -> real = a.real + b.real;
    p -> imaginary = a.imaginary + b.imaginary;
}
*/
void complexSubstract (const complex &a, const complex &b, complex *q) {
     q -> real = a.real - b.real;
     q -> imaginary = a.imaginary - b.imaginary;
}
/*
void complexMultiply (const complex &a, const complex &b, complex *r) {
     r -> real = (a.real * b.real) - (a.imaginary * b.imaginary);
     r -> imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
}

void complexDivide (const complex &a, const complex &b, complex *s) {
    int temp;
    temp = (b.real * b.real) + (b.imaginary * b.imaginary);
    s -> freal = (a.real * b.real) + (a.imaginary * b.imaginary);
    s -> freal /= temp;
    s -> fimaginary = (b.real * a.imaginary) - (a.real * b.imaginary);
    s -> fimaginary /= temp;
}*/    
int main() {
    Complex a, b, c;
    input (&a);
    input (&b);
 //   complexAdd (a, b, &c);
    complexSubstract (a, b, &c);
 //   complexMultiply (a, b, &c);
 //   complexDivide (a, b, &c);
    output (c);     
    return 0;
}
