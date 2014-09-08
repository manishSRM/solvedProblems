#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int  countInversion (const vector <int> &A, int N) {
    int Count = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (A[i] > A[j])
                Count++;
        }
    }
    return Count;
}

int countLocalInversion (const vector <int> &A, int N) {
    int Count = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i + 1])
            Count++;
    }
    return Count;
}

int main () {
    int T, N;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &N);
        vector <int> P (N + 1);
        for (int i = 1; i <= N; i++)
            scanf ("%d", &P[i]);
        int count1 = countInversion (P, N);
        int count2 = countLocalInversion (P, N);
        if (count1 == count2)
            printf ("YES\n");
        else
            printf ("NO\n");
    }
    return 0;
}
