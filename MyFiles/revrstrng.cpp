#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void revrsStrng (char str1[], int l) {
	int i, j;
	for (i = 0, j = l - 1; i < j; i++, j--) 
		swap (str1[i], str1[j]);	
	printf("%s\n", str1);	
}
int main()
{
	char str[51];
	 int l;
	 scanf ("%s", str);
	 l = strlen (str);
	 revrsStrng (str, l); 
	 return 0;
}
