#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char c = 'z';
	char *cp = &c;
	printf("cp is %p\n", cp);
	printf("The character at cp is %c\n", *cp);
	/* Pointer arithmetic - see what cp+1 is */
	cp = cp + 3; 
	printf("cp is %p\n", cp);
	/* Do not print *cp, because it points to
	memory not allocated to your program */

	return 0;
}
