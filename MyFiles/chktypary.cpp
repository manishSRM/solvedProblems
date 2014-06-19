#include<iostream>

using namespace std;

int main()
{
	int i, n, r = 0, a[50];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	if (a[r + 1] > a[r]) {
		for (i = 1; i < n; i++) {
			if (a[i + 1] > a[i])
				continue;
			else  {
			cout << "Increasing & decreasing  array \n";
			break; 
			}
		}
	cout << "Increasing array \n";
	} 
	else if (a[r + 1] < a[r]) {
		for (i = 1; i < n; i++) {
			if (a[i + 1] < a[i])
				continue;
			else  {
			cout << "Increasing & decreasing  array \n";
			break; 
			}
		}
	cout << "Decreasing array \n";
	}
	else if (a[r + 1] == a[r]) {
		for (i = 1; i < n; i++) {
			if (a[i + 1] == a[i])
			continue;
			else {
			cout << "Increasing & decreasing  array \n";
			break; 
			}
		}
		cout << "Constant array \n";	
	}
	else 
	cout << "Increasing & decreasing  array \n";
	return 0;
}
