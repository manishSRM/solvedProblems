#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 32000
#define N_M_MAX 1000000

using namespace std;

bool A[MAX + 1];
bool B[N_M_MAX + 1];
int storePrime[MAX];

void initalizeArray () {
    A[0] = A[1] = false;

    for(int i = 2; i <= MAX; i++) {
        A[i] = true;
    }

    for(int i = 2; i <= MAX / i; i++) {
        for(int j = i * i; j <= MAX; j += i) {
            A[j] = false;
        }
    }
}

int extractPrime () {
    int c = 0;
    for(int i = 2; i <= MAX; i++) {
        if(A[i] == true)
            storePrime[c++] = i;
    }
    return c;
}

void initalizeArray2 (int size, int m, int n) {
    int k;
    if(m == 1) {
        B[0] = false;
        k = 1;
    }
    else
        k = 0;    
    for(; k <= n - m; k++) 
        B[k] = true;
    for(int i = 0; storePrime[i] <=  n / storePrime[i]; i++) {
        int rem = m % storePrime[i];
        int def;
        if(rem == 0)
            def = 0;
        else
            def = storePrime[i] - rem;
        int start = m + def;
        if(start <= storePrime[i]) 
            start = 2 * storePrime[i]; 
        for(int j = start; j <= n; j += storePrime[i]) 
            B[j - m] = false;
    }   
}

void printArray (int len, int m) {
    for(int i = 0; i <= len; i++) {
        if(B[i] == true)
            printf("%d\n", m + i);
    }
    printf("\n");    
}

int main() {
    int T; 
    scanf("%d", &T);
    initalizeArray ();
    int size = extractPrime();
    for(int i = 0; i < T; i++) {
        long long int N, M;
        scanf("%lld %lld", &M, &N);
        initalizeArray2 (size, M, N);
        printArray(N - M, M);
        
    }        
    return 0;
}