#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

int main () {
    int c = 1;
    int b = --c+c+++c+++--c;
    printf("%d %d\n", c, b);
    return 0;
}