#include<iostream>

using namespace std;
int main()
{
	int i,j,n;
	cout << "Enter the size\n";
	cin >> n;
	for(i = 1; i <= n; ++i) {				//&&&&
		for(j = 1; j <= n; ++j) {			//&&&
                   if(( i + j) <= (n + 1))			//&
			cout << "&";
		   else
			cout << " ";
                    }
                   cout << "\n";
               }
            return 0;
}

