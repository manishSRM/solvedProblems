#include <cstdio>
#include <string.h>
#define MAX 100001

using namespace std;

int checkSubstring (char str[], int firstIndex) {
    if (str[firstIndex] == '0' && str[firstIndex + 1] == '1' && str[firstIndex + 2] == '0')
        return 1;
    else if (str[firstIndex] == '1' && str[firstIndex + 1] == '0' && str[firstIndex + 2] == '1')
        return 1;
    else
        return 0;
}

int main () {
    int T;
    char String[MAX];
    scanf ("%d", &T);
    while (T--) {
        int flag = 0;
        scanf ("%s", String);
        int len = strlen (String);
        for (int i = 0; i < len - 2; i++) {
            int result = checkSubstring (String, i);
            if (result == 1) {
                printf ("Good\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf ("Bad\n");
    }
    return 0;
}
