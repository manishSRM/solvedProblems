#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int A[110];

long long int maxDifference (int N, int K) {
    long long int sum = 0;
    int temp = 1, i, count;
    if(K <= N / 2)
        count = N - K;
    else
        count = K;
    for(i = N - 1; i >= 0; i--) {
        if(temp <= count) {
            sum += A[i];
            temp++;
        }
        else
            sum -= A[i];
    }    
    return sum;
}

int main () {
    int T;
    scanf("%d", &T);
    for(int c = 0; c < T; c++) {
        int N, K;
        scanf("%d %d", &N, &K);

        for(int i = 0; i < N; i++) 
            scanf("%d", &A[i]);

        sort(A, A + N);
        printf("%lld\n", maxDifference(N, K));
    }
    return 0;
}