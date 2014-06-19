#include<iostream>

using namespace std;

int main()
{
    int i, n, j, k, r;
    int array[100], EvenArray[100], OddArray[100];
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> array[i];
    }
    for (i = j = k = 0; i < n; ++i) {
        if (array[i] % 2 == 0) {
            EvenArray[j] = array[i];
            ++j;
        } 
        else {
            OddArray[k] = array[i];
            ++k;
        }
    }
    for (i = r = 0; i < n; ++i) {
        if (k > i)
            array[i] = OddArray[i];
        else {
            array[i] = EvenArray[r];
            ++r;
        }
    }
    for (i = 0; i < n; ++i)
        cout << array[i] << "  ";
    cout << "\n";
    return 0;
}

/*

*/

