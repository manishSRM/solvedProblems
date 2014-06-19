#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
int main()
{
	char str[20];
	int i, j, l, m, flag = 1;
	gets (str);
	l = strlen (str);
	m = l / 2 + 1;
	for (i = 0, j = l-1; i < m && j >= m; ++i, --j) {
			if (str[i] != str[j])
			   flag = 0;
		     }
	if (flag == 0)
	cout << "string is not palindromed \n";
	else
	cout << "String is palindrome \n";
	return 0;
}
