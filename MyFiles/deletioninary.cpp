#include<iostream>

using namespace std;

void deletnumber (int ar[], int n, int index)  {
	int i, j;
	for (i = index; i < n ; ++i) {
		ar[i] = ar[i + 1];
	}
	for (j = 0; j < n - 1; ++j)
		cout << ar[j] << " ";

	return;
} 
int main ()
 {
	int  ar[] = {6, 4, 7, 3, 9, 10, 1, 5};
	cout << "After deletion array =";
	deletnumber (ar, 8, 5);
	cout << "\n";
       return 0;
}


