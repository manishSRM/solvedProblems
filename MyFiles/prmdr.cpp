#include<iostream>

using namespace std;

void uptrngl(int n) {
  int i, j;
  for (i = 1; i <= n; ++i) {
	for(j = 1; j <= n; ++j)  {
	    if (i + j >= n + 1)
		cout << "&";
	    else
		cout << " ";
           }
	cout << "\n";
     }
    return;		
}
void downtrngl( int n) {
   int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= n; ++j) {
		    if ( i <= j )
			cout << "&";
 		    else
			cout << " ";
		}
		cout << "\n";
          }
        return;	
}

int main()
{	
	int size, m;
	cin >> size;
	m = size/2 + 1;
	uptrngl(m);
	downtrngl(size-m);
	return 0;
}
