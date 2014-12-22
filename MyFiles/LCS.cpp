#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
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
typedef vector<char> VC;

void getInput(VC &X, int size) {
    X.push_back(0);
    FOR(i, 0, size) {
    	char C, temp;
    	scanf("%c%c", &C, &temp);
    	X.push_back(C);
    }
}

void LCS_LENGTH(const VC &X, const VC &Y, VVI &c, VVI &b) {
    int m = X.size() - 1;
    int n = Y.size() - 1;
    EFOR(i, 0, m) {
        c[i][0] = 0;
    }
    EFOR(j, 0, n) {
        c[0][j] = 0;
    }
    EFOR(i, 1, m) {
        EFOR(j, 1, n) {
            if(X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } else if(c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '-';
            }   
        }
    }
    return;
}   

void PRINT_LCS(const VVI &b, const VC &X, int i, int j) {
    if(!i || !j)
        return;
    if((b[i][j]) == '\\') {
        PRINT_LCS(b, X, (i - 1), (j - 1));
        printf("%c\n", X[i]);
    } else if(b[i][j] == '|') {
        PRINT_LCS(b, X, (i - 1), j);
    } else {
        PRINT_LCS(b, X, i, (j - 1));
    }
}

int main () {
    VC X, Y;
    int m, n;
    char s;
    SC(m); SC(n);
    scanf("%c", &s);
    getInput(X, m);
    getInput(Y, n);
    vector<vector<int> >c((m + 1), vector<int>(n + 1));
    vector<vector<int> >b((m + 1), vector<int>(n + 1));
    LCS_LENGTH(X, Y, c, b);
    PRINT_LCS(b, X, m, n);
    return 0;
}
