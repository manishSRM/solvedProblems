#include <cstdio>
#include <algorithm>
#define MAX 10010

using namespace std;

struct Table { 
    long long int cells;
    int cost;
}T1[MAX];

int cmp (Table t1, Table t2) {
    return t1.cost < t2.cost;
}

int main () 
{
    long long int N, M, sum = 0;
    int H;
    scanf ("%lld%lld%d", &N, &M, &H);
    for (int i = 0; i < H; i++) {
        scanf ("%lld%d", &T1[i].cells, &T1[i].cost);
        sum += T1[i].cells;
    } 
    if (sum < M * N) {
        printf("Impossible\n");
        return 0;
    }
    sort (T1, T1 + H, cmp);
    long long int temp = 0, TotalCost = 0;
    for (int i = 0; i < H; i++) {
        if (temp + T1[i].cells > M * N) {
            TotalCost += ((M * N) - temp) * T1[i].cost;
            break;
        }
        temp += T1[i].cells;
        TotalCost += T1[i].cells * T1[i].cost;
    }
    printf("%lld\n", TotalCost);
    return 0;
}