#include<iostream>
#include<stdio.h>
					// address, values stored and the memory size of all six variables
using namespace std;

int main()
{
	int num = 10, *iptr;
	char ch = 'a', *cptr;
	double dub = 19.666, *dubl;
	iptr = &num;
	cptr = &ch;
	dubl = &dub;
	printf ("\nAddress of variables = ");
	printf ("%p, %p, %p, %p, %p, %p \n ", iptr, cptr, dubl, &iptr, &cptr, &dubl);
	printf ("\nValues all vairables and pointers = ");
	printf ("%d, %c, %lf, %p, %p, %p \n", num, ch, dub, iptr, cptr, dubl);
	printf ("\nSize of all variables and pointers = ");
	printf (" %d, %d, %d, %d, %d, %d \n\n", sizeof (num), sizeof (ch), sizeof (dub), sizeof (iptr), sizeof (cptr), sizeof (dubl));
	return 0;
}
