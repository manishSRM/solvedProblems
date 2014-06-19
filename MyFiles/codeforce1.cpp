#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main () 
{
    int n, v;
    int A[3010], B[3010];
    scanf("%d%d", &n, &v);
    int maxDay = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &A[i], &B[i]);
        maxDay = max (maxDay, A[i] + 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                swap(B[j], B[j-1]);
            }
        }
    }
    int ans = 0;
    for (int currentDay = 1; currentDay <= maxDay; currentDay++) {
        //trace1(currentDay);
        int leftToCollect = v;
        for (int i = 0; i < n; i++) {
            if (A[i] == currentDay || A[i] + 1 == currentDay) {
                int collected = min (leftToCollect, B[i]);
                leftToCollect -= collected;
                B[i] -= collected;
                ans += collected;
               // trace5(ans, collected, i, A[i], B[i]);
            }
        }
    }
    printf("%d", ans);
    return 0;
}