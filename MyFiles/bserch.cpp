#include<iostream>

using namespace std;

int bSearch (int ar[], int n, int num)   {
	int i, beg = 0, last = n - 1, mid;
	while (beg <= last)  {
		mid = (beg + last) / 2;
		if (ar[mid] == num)
			return 1;
		else if (ar[mid] > num)
            last = mid - 1;
		else
		    beg = mid + 1;		 					
	}
    return 0;
}
int main()
{
	int ar[40], i, n, numS;
	cin >> n;
	for (i = 0; i < n; ++i) 
	   cin >> ar[i];

	cout << "Enter element for search \n";
	cin >> numS;
	cout <<"Result = " << bSearch (ar, n, numS) << "\n";
	return 0;
} 
