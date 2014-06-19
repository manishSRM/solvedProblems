#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i, array[100], n;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> array[i];
    }
    int flag = 0;
    while (flag == 0) {
        flag = 1;
        for (i = 0; i < n; ++i) {
            if (array[i] % 2 == 0 && array[i + 1] % 2 != 0)  {
                swap (array[i], array[i +  1]);
                flag = 0;
            }
        }
    }
	for (i = 0; i < n; ++i) 
        cout << array[i] << "  ";
        cout << "\n";
    return 0;
}

