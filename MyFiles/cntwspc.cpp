#include<iostream>
#include<stdio.h>
using namespace std;

int lengthOfString (char ch[]) {
    int i;
    for (i = 0; ch[i] != '\0'; ++i);
    return i;
}

int main()
{
    int i, count = 0;
	char str[51];
	cout << "Enter the text\n";
	gets (str);
	cout << "length = " << lengthOfString (str);
    return 0;    		
} 
