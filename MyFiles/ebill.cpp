#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
	 int unit;
	char name[ 40 ];
	float blnc;
	cout << " Enter the name of user \n";                                //electric bill
	gets( name );
 	cout << "Enter the total units of the user \n";
 	cin >> unit;
 	if( unit <= 100 )
    	blnc = ( unit * 0.4 ) + 50;
 	else if ( unit <= 300 )
    	blnc = ( unit * 0.5 ) + 50;
 	else
   	blnc = ( unit * 0.6 ) + 50;

 	cout << "name of user is= ";
    	puts( name );
	cout << "\n"; 
 	cout << " total balance= " << blnc << "\n \n";
	return 0;
} 
