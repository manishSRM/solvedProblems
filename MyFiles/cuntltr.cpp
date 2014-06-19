#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int i, count = 0;
	char str[51];
	cout << "Enter the text\n";
	gets( str );
	for( i = 0; str[ i ] != '\0'; ++i) {
		if( str[ i ] == '\n')
		    break;	
		else
	             ++count;
              }
	     cout << "number of letters= " << count;  	
        return 0;    		
	} 
