#include <iostream>
#include <stdio.h>

using namespace std; 

struct complex {
    int real;
    int imaginary;
};

void input (complex *a) {
	printf("kjhfdj\n");
    scanf ("%d", &(a->real));
    scanf ("%d", &(a->imaginary));
}

void output (const complex &b) {
    printf ("%d + i%d\n", b.real, b.imaginary);
}

void complexSum ( complex *sum, const complex &m) {
    sum->real += m.real;
    sum->imaginary += m.imaginary;
}

int main() {
    complex numbers[2], sum;
    sum.real = 0;
    sum.imaginary = 0;
    for (int i = 0; i < 2; i++) {
        input (&numbers[i]);
        complexSum (&sum, numbers[i]);
    }
    output (sum);
    return 0;
}    
