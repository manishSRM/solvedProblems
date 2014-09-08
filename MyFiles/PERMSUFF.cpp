#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <list>
#include <set>
#include <map>
#include <string>

#define INF 1000000000
#define MOD 1000000007

#define _DEBUG 1

#if _DEBUG

#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define SS(n) scanf("%d", &n);

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int A[100010];
pair<int, int> B[100010];

int solve () {
    int n, m;
    SS(n); SS(m);
    for (int i = 1; i <= n; i++) {
        SS(A[i]);
    }
    for (int i = 0; i < m; i++) {
        SS(B[i].first); SS(B[i].second);
    }
    sort(B, B + m);

    vector<ii> exclusivePairs;

    int current = 0;
    while (current < m) {
        int currentStart = B[current].first;
        int currentEnd = B[current].second;
        int next = current + 1;
        while (next < m && B[next].first <= currentEnd) {
            currentEnd = max(currentEnd, B[next].second);
            next ++;
        }
        exclusivePairs.push_back(ii(currentStart, currentEnd));
        current = next;
    }

    for (int i = 0; i < exclusivePairs.size(); i++) {
        sort(A + exclusivePairs[i].first, A + exclusivePairs[i].second + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] != i) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int testCases;
    SS(testCases);
    while (testCases--) {
        printf("%s\n", (solve() ? "Possible" : "Impossible"));
    }
    return 0;
}