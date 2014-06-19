#include<iostream>

using namespace std;

int main()
{
    int a[20], i, j, n, flag;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++) {
		if (i != n - 1)
			a[i] = a[i + 1] - a[i];
		else
			a[i] = a[i - 1];		
	}
	cout << "Array becomes \n";
	for (j = 0; j < n; j++)
		cout << a[j] << " ";
    cout << "\n";    
    flag = 0;
	for (i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1])  { 
           flag = 1;
           break;
        }
    }
    if (flag == 0) {
        if (a[0] >= 0)
            cout << "Array is Increasing  A.P. \n";
        else
            cout << "Array is Decreasing  A.P. \n";
    } else
        cout <<  cout << "Array is not A.P. \n";
	return 0;
}

