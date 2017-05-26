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

void allSubsets(const string &str, vector<string> &ans, int index, vector<bool> &mask) {
    if (index > str.length()) {
        return;
    }
    if (index == str.length()) {
        string temp = "";
        for (int k = 0; k < str.length(); k++) {
            if (mask[k]) {
                temp += str[k];
            }
        }
        ans.push_back(temp);
    }
    mask[index] = false;
    allSubsets(str, ans, index+1, mask);
    mask[index] = true;
    allSubsets(str, ans, index+1, mask);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        vector<string> ans;
        vector<bool> mask(str.length(), false);
        allSubsets(str, ans, 0, mask);
        FOR (i, 1, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}







