#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <iomanip>
#include <list>
#include <set>
#include <deque>
#include <bitset>
#include <map>
#include <assert.h>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define MAX 1002
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

int main() {
    int T;
    SC(T);
    while(T--) {
        char str[MAX];
        scanf("%s", str);
        int len = strlen(str);
        VI count(30, 0);
        FOR(i, 0, len) {
            if(len % 2 && i == len / 2) {
                continue;
            }
            count[str[i] - 97]++;
        }
        VI firstHalf(30, 0);
        FOR(j, 0, len / 2) {
            firstHalf[str[j] - 97]++;
        }
        int flag = 1;
        FOR(k, 0, 29) {
            if(firstHalf[k] * 2 != count[k]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
