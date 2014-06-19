#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[] = {12, 34, 14, 89, 100} , i = 0, j;
	swap (a[i + 4], a[i + 1]);
	swap (a[i + 1], a[i +2]);
	swap (a[i], a[i + 4]);
	swap (a[i + 3], a[i +2]);
	cout << "After shuffling array will be = \n";
	for (j = 0; j < 5; j++)
		cout << a[j] << "  ";
	cout << "\n";	
	return 0;
}
