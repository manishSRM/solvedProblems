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

vector<int> storeDigitsInVector(long long N) {
    vector<int> A;
    while (N) {
        A.push_back(N % 10);
        N /= 10;
    }
    reverse(A.begin(), A.end());
    return A;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    int sizeOfA = A.size();
    int sizeOfB = B.size();
    int columnSize = (2 * sizeOfA + sizeOfB);
    int rowSize = sizeOfB;
    int c = 0;
    vector<vector<int> > grid(rowSize, vector<int>(columnSize, 0));
    for (int i = sizeOfB - 1; i >= 0; i--) {
        int carry = 0, fillingIndex = columnSize - c - 1;
        for (int j = sizeOfA - 1; j >= 0; j--) {
            int mul = A[j] * B[i] + carry;
            grid[c][fillingIndex] = mul % 10;
            fillingIndex--;
            carry = mul / 10;
        }
        if (carry) {
            grid[c][fillingIndex] = carry;
            carry = 0;
        }
        c++;
    }
    vector<int> ans;
    int anotherCarry = 0;
    for (int i = columnSize - 1; i >= 0; i--) {
        int sum = 0;
        for (int j = rowSize - 1; j >= 0; j--) {
            sum += grid[j][i];
        }
        sum += anotherCarry;
        ans.push_back(sum % 10);
        anotherCarry = sum / 10;
    }
    while (anotherCarry) {
        ans.push_back(anotherCarry % 10);
        anotherCarry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    long long A, B;
    cin >> A >> B;
    vector<int> A1 = storeDigitsInVector(A);
    vector<int> A2 = storeDigitsInVector(B);
    vector<int> ans = solve(A1, A2);
    int len = ans.size();
    queue<int> Q;
    int i = 0;
    while (!ans[i]) { i++; }
    for(; i < len; i++) {
        Q.push(ans[i]);
    }
    while (!Q.empty()) {
        cout << Q.front();
        Q.pop();
    }
    cout << endl;
    return 0;
}





