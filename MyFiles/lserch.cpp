#include<iostream>

using namespace std;
int lSerch (int ar[], int num ) {
	int i;	
	for (i = 0; i < 10; ++i) {
		   if ( ar[i] == num)
			return 1;
		   else
			continue;			
		}
	}
int main() 
{
	int ar[10],i, n;
	for (i = 0; i < 10; ++i)
		cin >> ar[i];
	cout << "Enter number for search \n";
	cin >> n;
	cout << "Result= " << lSerch( ar, n) << "\n";
	return 0;
} 
