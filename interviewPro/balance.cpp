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

string findBalancedString(const string &str) {
    int len = str.length();
    if (!len) {
        return "";
    }
    stack<int> S;
    vector<bool> V(len, true);
    for (int i = 0; i < len; i++) {
        if (str[i] == ')') {
            if (!S.empty()) {
                S.pop();
            } else {
                V[i] = false;
            }
        } else {
            S.push(i);
        }
    }
    while(!S.empty()) {
        V[S.top()] = false;
        S.pop();
    }
    string ans = "";
    for (int k = 0; k < len; k++) {
        if (V[k]) {
            ans += str[k];
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        string ans = findBalancedString(str);
        cout << ans << endl;
    }
    return 0;
}



