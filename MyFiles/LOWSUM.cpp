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
#define SCC(A) scanf("%lld", &A)

using namespace std;

typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

void find_K_sums(const VLI &A, const VLI &B, int K, priority_queue <lint> &Q) {
    int counter = 0, flag = 0;
    EFOR(i, 1, K) {
        EFOR(j, 1, K) {
            counter++;
            if(counter >= 10000) {
                flag = 1;
                break;
            }
            Q.push(A[i] + B[j]);
        }
        if(flag)
            break;
    }
    return;
}

void copyQueue(priority_queue<lint> &Q, VLI &copy) {
    while(!Q.empty()) {
        copy.push_back(Q.top());
        Q.pop();
    }
    return;
}

void solveQuery(const VLI &copy, int N) {
    int sizeOfQueue = copy.size();
    int possibleN = sizeOfQueue - N;
    printf("%lld\n", copy[possibleN]);
}

int main() {
    int T;
    SC(T);
    while(T--) {
        int K, query;
        SC(K); SC(query);
        VLI A(K + 1), B(K + 1);
        EFOR(i, 1, K)
            SCC(A[i]);
        EFOR(j, 1, K)
            SCC(B[j]);
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<lint> Q;
        find_K_sums(A, B, K, Q);
        VLI copy;
        copyQueue(Q, copy);
        while(query--) {
            int queryNum;
            SC(queryNum);
            solveQuery(copy, queryNum);
        }
    }
    return 0;
}