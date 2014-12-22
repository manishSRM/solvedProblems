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
#define MAX_NUM 1002

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;
typedef map<int,int> MP;

int countBits(int N) {
    if(!N)
        return 0;
    int count = 1;
    while(N >>= 1)  
        count++;
    return count;  
}

void setUpBuckets(VVI &bucket, const VI &inputList, const VI &binaryLength) {
    int N = inputList.size();
    FOR(i, 0, N) {
        bucket[binaryLength[inputList[i]]].push_back(inputList[i]);
    }
}

void gaussianElimination(VVI &bucket, VI &modifiedList, const VI &binaryLength) {
    int N = bucket.size();
    RFOR(i, (N - 1), 0) {
        if(!bucket[i].size())
            continue;
        int X = bucket[i][0];
        modifiedList.push_back(X);
        FOR(j, 1, bucket[i].size()) {
            int Y = bucket[i][j] ^ X;
            if(Y) {
                bucket[binaryLength[Y]].push_back(Y);
            }
        }
    }
}

void findmaximumXOR(const VI &modifiedList, int K, const VI &binaryLength) {
    int S = modifiedList.size();
    int ans = K;
    FOR(i, 0, S) {
        if(ans < (ans ^ modifiedList[i]))
            ans ^= modifiedList[i];
    }
    printf("%d\n", ans);
}

void storeBinaryLength(VI &binaryLength) {
    int size = binaryLength.size();
    FOR(i, 0, size) {
        binaryLength[i] = countBits(i);
    }
} 

int main() {
    int T;
    SC(T);
    VI binaryLength(MAX_NUM);
    storeBinaryLength(binaryLength);
    while(T--) {
        int N, K, maxNum = INT_MIN;
        VI inputList;
        SC(N); SC(K);
        FOR(i, 0, N) {
            int x;
            SC(x);
            inputList.push_back(x);
            maxNum = max(maxNum, x);
        }
        int lenK = binaryLength[K];
        int S = max(binaryLength[maxNum], lenK);
        VVI bucket(S + 1);
        VI modifiedList;
        setUpBuckets(bucket, inputList, binaryLength);
        gaussianElimination(bucket, modifiedList, binaryLength);
        findmaximumXOR(modifiedList, K, binaryLength);
    }
    return 0;
}