#include<iostream>
#include<stdio.h>

using namespace std;

int chekSubString (char ch1[], char ch2[]) {
	int i, j, flag = 1;
	for(i = 0; ch1 [i] != '\0'; ++i) {
		for (j = 0; Ch2 [j] != '\0'; ++j) {
			if (ch1[i] == ch2[j]) {
			     for (;i >=j; ++i,++j) {
					if (ch1[i] != ch2[j]) {
					flag = 0;
					return flag;
					}
					else 
					return flag; 
				}	
			}
		}
	}
     return 0;
}
int main()
{
	char str1[51], str2[51];
	gets (str1);
	gets (str2);
	int chekSubStrng (char ,char);
	cout << "Result= " << chekSubStrng (str1, str2) << "\n";
	return 0;
}
