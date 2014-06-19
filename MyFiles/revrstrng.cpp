#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
void revrsStrng (char str1[], int l) {
	int i, j;
	for (i = 0, j = l; i < j; ++i, --j) {
		char ch;
		ch = str1[i];
		str1[i] = str1[j];
		str1[j] = ch;	
		}
		puts (str1);	
}
int main()
{
	char str[51];
	 int l;
	 gets(str);
	 l = strlen (str);
	 revrsStrng (str, l); 
	 return 0;
}
