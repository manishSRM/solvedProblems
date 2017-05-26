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

VI computeLpsArray(const string &pattern) {
    int len = 0, i = 1;
    int M = pattern.length();
    VI lps(M, 0);
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(const string &text, const string &pattern) {
    int M = pattern.length();
    int N = text.length();
    VI lps = computeLpsArray(pattern);
    int i = 0, j = 0;
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == M) {
            cout << "Found Patter At index : " << (i - j) << endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return;
}

int main() {
    int T;
    SC(T);
    while (T--) {
        string text, pattern;
        cin >> text >> pattern;
        KMPSearch(text, pattern);
    }
    return 0;
}







