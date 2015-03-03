#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define lint long long int
#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

void checkIfMatchingPossible(char text[], int &i, int &j, VI &prefixArray, int len) {
    FOR(k, 1, len) {
        if(text[k] == text[i]) {
            prefixArray[i] = prefixArray[i - 1] + 1;
            i++;
        } else {
            return;
        }
    }
}

void createPrefixArray(char text[], VI &prefixArray, int len) {
    prefixArray[0] = 0;
    int i = 1, j = 0;
    while(i < len) {
        if(text[i] == text[j]) {
            prefixArray[i] = prefixArray[i - 1] + 1;
            i++;
            checkIfMatchingPossible(text, i, j, prefixArray, len);
        } else {
            prefixArray[i] = 0;
            i++;
        }
    }
}

int main() {
    char text[] = "AAABAAA";
    int len = strlen(text);
    VI prefixArray(len + 1);
    createPrefixArray(text, prefixArray, len);
    FOR(k, 0, len) {
        printf("%d ", prefixArray[k]);
    }
    printf("\n");
    return 0;
}