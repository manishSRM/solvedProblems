#include<iostream>

using namespace std;

void upTriangle (int n) {
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i >= j)
                cout << "&";
            else 
                cout << " ";
        }
        cout << "\n";
    }
}

void downTriangle (int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if ((i + j) <= n + 1)
                cout << "&";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

int main () {
    int n, m;
    cin >> n;
    m = n / 2 + 1;
    upTriangle (m);
    downTriangle (n - m);
    return 0;
}

