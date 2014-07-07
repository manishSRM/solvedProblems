#include <cstdio>
#include <algorithm>

#define MAX 100010
#define FOR(A, B, C) for (int A = B; A <= C; A++)

using namespace std;

int permutaion[MAX];

int main ()
{
    int N, Q;
    scanf ("%d %d", &N, &Q);
    FOR(i, 1, N)
        scanf ("%d", &permutaion[i]);
    int x, y;   
    FOR(j, 1, Q) {
        scanf ("%d %d", &x, &y);
        swap (permutaion[x], permutaion[y]);
        int count = 0;
        FOR(i, 1, N) {
            FOR(j, i + 1, N) {
                if (permutaion[i] > permutaion[j])
                    count++;
            }
        }
        printf("%d\n", count % 2); 
    }   
    return 0;
}