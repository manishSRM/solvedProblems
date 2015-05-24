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
    FOR(i, 0, T) {
        char str[108];
        scanf("%s", str);
        VB check(120, false);
        for(int j = 0; str[j] != '\0'; j++) {
            check[str[j]] = true;
        }
        int c = 0;
        for(int k = 64; k < 105; k++) {
            if(check[k] == true) {
                c += 1;
            }
        }
        if(c == 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}



