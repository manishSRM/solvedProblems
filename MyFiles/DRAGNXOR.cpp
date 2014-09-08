#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int storeInBinary (int N, int A) {
    int c = 0;
    while (A) {
        if (A % 2 == 1)
            c++;
         A /= 2;
    }
    return c;
}

int findPower (int N) {
    int result = 1;
    for (int i = 1; i <= N; i++) {
        result *= 2;
    }
    return result;
}

long long int makeNumber (int N, int Count) {
    int finalIndex = N - Count;
    long long int sum = 0;
    for (int i = N - 1; i >= finalIndex; i--)
        sum += findPower (i);
    return sum;
}

int main () {
    int T, N, A, B;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &N, &A, &B);
        int count1 = storeInBinary (N, A);
        int count2 = storeInBinary (N, B);
        if ((count1 + count2) > N)
            printf ("%lld\n", makeNumber (N, 2 * N - (count1 + count2)));
        else
            printf ("%lld\n", makeNumber (N, (count1 + count2)));
    }
    return 0;
}
