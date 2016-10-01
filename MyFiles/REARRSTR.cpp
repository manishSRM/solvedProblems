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
#define MAX 100002
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef pair<int,char> PCI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;
typedef vector<PCI> VCI;

void findFrequency(char str[], VCI &frequency, int len) {
    VI C(130, 0);
    FOR(i, 0, len) { C[str[i]]++; }
    FOR(j, 97, 127) {
        if(C[j]) {
            frequency.push_back(make_pair(C[j], char(j)));
        }
    }
    return;
}

int main() {
    int T;
    SC(T);
    while(T--) {
        char str[MAX];
        scanf("%s", str);
        VCI frequency;
        int len = strlen(str);
        findFrequency(str, frequency, len);
        sort(frequency.rbegin(), frequency.rend());
        int pos = 0;
        char answer[len];
        VCI :: iterator it = frequency.begin();
        for(; it != frequency.end(); it++) {
            int size = it -> first;
            char C = it -> second;
            FOR(j, 0, size) {
                answer[pos] = C;
                pos += 2;
                if(pos >= len) {
                    pos = 1;
                }
            }
        }
        answer[len] = '\0';
        bool OK = true;
        FOR(k, 1, len) {
            if(answer[k] == answer[k - 1]) {
                OK = false;
            }
        }
        if(OK) {
            printf("%s\n", answer);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}


