#include<stdio.h>

using namespace std;

int main () {
    int total_test, i, product = 1, m;
    scanf ("%d", &total_test);
    for (i = 1; i <= total_test; i++) {
        int temp;
        for (int j = 1; j <= temp; j++) {
            int  num;
            scanf ("%d", &num);
            product *= num;
        }
        for (int k = 2; k <= product; k++) {
            if (product % k == 0)
                m++;
        }
        printf ("%d", m);
    }
    return 0;
}
