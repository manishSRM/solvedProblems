#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <set>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

using namespace std;

void printPossibleValue_P_Q (int M) {

    for (int i = 0; i <= M; i++) {
        if (M - (2 * i) <= M && M - (2 * i) >= 0)
            printf("(%d %d)\n", i, M - (2 * i));
    }
    return;
}

int main () 
{
    int M = 10;
    printPossibleValue_P_Q (M);
    return 0;
}