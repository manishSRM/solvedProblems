#include<iostream>

using namespace std;

int main () {
    int i, j, k, l, n, m;
    cin >> m;
    n = 2 * m - 1;
    k = 1;
    l = n;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (j >= k && j <= l)
                cout << "*";
            else
                cout << " ";
        }
        ++k;
        --l;
        cout << "\n";
    }
    return 0;
}
