#include<iostream>

using namespace std;

int main () {
    int i, j, m;
    cin >> m;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1 && j >= 1 ) 
                cout << "*";
            else if( j == 1 && i >= 1)
		cout << "*";
	    else if( i == m && j >= 1)
		cout << "*";
	    else if(j ==m && i >= 1)			
          	cout << "*";
            else
		cout<<" ";		
        }

        cout << "\n";
    }
    return 0;
}
