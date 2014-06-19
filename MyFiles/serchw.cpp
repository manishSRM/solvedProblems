#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int i;
	char ch, str[ 110], flag = 'n';
	puts(" Enter the text \n");
	gets( str );
	puts(" Enter the word for searching ");
	cin >> ch;
	for( i = 0; str [ i] != '\0'; ++i) {
		if(str [ i ] == ch) {
		  cout << "The input word is found in the text \n";
			flag = 'y';
			}
		}
	    if( flag == 'n')	
	    cout<<" The word is not in text \n"; 	
	return 0;	 	 
}
