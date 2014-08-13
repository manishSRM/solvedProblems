#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int main () {
    int T; 
    long long int N;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%lld", &N);
        printf("%lld\n", N - 1);
    }
    return 0;
}