#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;
int max (int a, int b) {
    return (a > b) ? a : b;
}

int max (int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum (int A[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= low; i--) {
        sum += A[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = 0;
    for(int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if(sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

int maximumSubArraysum (int A[], int low, int high) {
    if(low == high)
        return A[low];
    int mid = (low + high) / 2;
    return max(maximumSubArraysum(A, low, mid), maximumSubArraysum(A, mid + 1, high), maxCrossingSum(A, low, mid, high));

}

int main () {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int max = maximumSubArraysum (A, 0, N - 1);
    printf("%d\n", max);
    return 0;
}
