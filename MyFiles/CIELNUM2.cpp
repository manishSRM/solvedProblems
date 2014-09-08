#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int main ()
{
    int T, count = 0;
    char str[256], C;
    scanf ("%d", &T);
    scanf ("%c", &C);
    while (T--) {
        gets (str);
        int count_3 = 0, count_5 = 0, count_8 = 0; 
        for (int i = strlen (str) - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                if (count_8 >= count_5 && count_5 >= count_3) 
                    count++;
                break;
            }
            if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '7' || str[i] == '9')
                break;
            if (str[i] == '8')
                count_8++;
            else if (str[i] == '5')
                count_5++;
            else if (str[i] == '3')
                count_3++;
        }
    } 
    printf("%d\n", count);
    return 0;
}