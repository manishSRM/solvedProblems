#include<iostream>
#include<algorithm>

using namespace std;
void bubbleSort (int ar[], int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < (n - 1 - i); ++j) {
            if (ar[j] > ar[j + 1]) 
                swap (ar[j], ar[j + 1]);
        }
    	for (j = 0; j < n; ++j)
    		cout << ar[j] << " ";
	cout << "\n";
    }
	return;
}
int main()
{
	int ar[] = {6, 4, 7, 3, 9, 1, 5};
	cout << "Sorted array = \n";
    bubbleSort (ar, 7);
	return 0;
}
