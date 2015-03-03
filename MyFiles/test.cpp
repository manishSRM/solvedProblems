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

int doesPatternExist(char text[], int index, char pattern[], int m) {
    int c = 0;
    FOR(i, index, (index + m)) {
        if(text[i] != pattern[c++])
            return 0;
    }
    return 1;
}
int searchStringOccurance(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    EFOR(i, 0, (n - m)) {
        if(doesPatternExist(text, i, pattern, m))
            return i;
    }
    return -1;
}

int main() {
    char text[] = "AAKLJKHSJHHGHIKGILJSKJHJB";
    char pattern[] = "IKG";
    int result = searchStringOccurance(text, pattern);
    printf("%d\n", result);
    return 0;
}