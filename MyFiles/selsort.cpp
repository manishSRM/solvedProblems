#include<iostream>
#include<algorithm>

using namespace std;

void SelSorting (int ar[], int n) {
    int i, small, k, j, temp;
    for (i = 0; i < n; ++i) {
        small = ar[i];
        k = i;
        for (j = i + 1; j < n; ++j) {
            if (small > ar[j]) {
                small = ar[j];
                k = j;          
            }
        }
        swap (ar[i], ar[k]);
        for (j = 0; j < n; ++j)
            cout << ar[j] << "  ";
        cout <<"\n";
    }
    return;
}
int main()
{
    int  ar[] = {6, 4, 7, 3, 9, 1, 5};
    int i, n;
    cout << "sorted array is= " << "\n";
    SelSorting (ar, 7);
    return 0;
}
