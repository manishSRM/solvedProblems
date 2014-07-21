#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <utility>
#include <string.h>
    
using namespace std;

struct add {
    int hour;
    char colon;
    int minute;
} ad1;

int main () {
    scanf ("%d %c %d", &ad1.hour, &ad1.colon, &ad1.minute);
    printf("%d%c%d\n", ad1.hour, ad1.colon, ad1.minute);
    return 0;
}