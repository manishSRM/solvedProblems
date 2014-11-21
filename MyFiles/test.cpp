#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits.h>  
#include <stack>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)

#define SC(A) scanf("%d", &A)
#define PF(A) printf("%d", A)
#define SCC(A) scanf("%lld", &A)

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

int ApowB(int A, int B, int M) {
    int result = 1;
    while(B) {
        if(B & 1) 
            result = (result * A) % M;
        A = (A * A) % M; 
        B >>= 1; 
    }
    return result % M;
}

int checkPrime(int Num) {
    int flag = 1;
    for(int i = 2; i <= Num / i; i++) {
        if(Num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void initializeMatrix(int matrix[][7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[5][1] = matrix[5][2] = matrix[5][3] = matrix[5][4] = matrix[5][5] = matrix[5][6] = 95;
    matrix[0][2] = matrix[0][3] = matrix[0][4] = 95;
    matrix[1][2] = matrix[3][2] = matrix[1][5] = matrix[2][5] = matrix[3][5] = matrix[4][5] = matrix[5][5] = 124;
    matrix[2][2] = 42;
    matrix[3][1] = matrix[4][1] = 47;
    matrix[3][3] = matrix[4][3] = 92;
}

int main() {
    printf("%d\n", 'O');
    int matrix[7][7];
    initializeMatrix(matrix);
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(matrix[i][j] != 0) 
                printf("%c", matrix[i][j]);
            else 
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}