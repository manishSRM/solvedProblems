#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 100

bool A[MAX + 1];

using namespace std;

int main() {

    A[0] = A[1] = false;
    for(int i = 2; i <= MAX; i++) {
        A[i] = true;
    }

    for(int i = 2; i <= MAX / i; i++) {
        for(int j = i * i; j <= MAX; j += i) {
            A[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= MAX; i++) {
        if(A[i] == true) {
            count++;
            printf("%d\n", i);
        }
    }
    //printf("%d\n", count);
    return 0;
}

