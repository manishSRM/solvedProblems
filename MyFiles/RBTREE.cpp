#include <cstdio>
#include <algorithm>
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

using namespace std;

typedef long long int lint;
typedef vector<bool> VB;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<lint> VLI;
typedef vector<PI> VPI;
typedef vector<VI> VVI;

int ApowB(int A, int B) {
    int result = 1;
    while(B) {
        if(B & 1) 
            result = (result * A);
        A = (A * A);
        B >>= 1; 
    }
    return result;
}

int findLevelOfNode(int N) {
	int i = 0;
    while(1) {
        int R = ApowB(2, i);
        if(R <= N && N <= (2 * R - 1)) {
            //printf("%d\n", i);
            break;    
        }
        i++;
    }
    return i;
}

int convertInBinary (int A[], long long int num) {
	int count = 0;
	while (num) {
		A[count++] = (int)num % 2;
		num /= 2;
	}
	return count;
}

void reverseArray (int array[], int size) {
	int temp = size - 1;
	for (int c = 0; c < size / 2; c++) 
		swap (array[c], array[temp--]);
}

int countCommonTerms (int A[], int B[], int n1, int n2) {
	if (n1 > n2)
		swap (n1, n2);
	int count = 0;
	FOR(i, 0, n1) {
		if (A[i] == B[i])
			count++;
		else
		    break;
	}
	return count;
}

int calculateSteps(int x, int y) {
	int I[40], J[40];
	int n1 = convertInBinary (I, x);
	int n2 = convertInBinary (J, y);
	reverseArray (I, n1);
	reverseArray (J, n2);
	int K = countCommonTerms (I, J, n1, n2);
	return ((n1 + n2) - 2 * K);
}

int main () {
	int Q;
	SC(Q);
	int flag = 0;
	while(Q--) {
		char str[4];
		int x, y;
		scanf("%s", str);
		if(str[1] == 'i') {
			flag = (flag + 1) % 2;
		} 
		else {
			SC(x); SC(y);
			int levelOfMaxNode1 = findLevelOfNode(x);
			int levelOfMaxNode2 = findLevelOfNode(y);
			int steps = calculateSteps(x, y);
			steps += 1;
			int flag2 = ((levelOfMaxNode1 % 2 == levelOfMaxNode2 % 2)) ? 1 : 0; 
			if(flag2 == 0 && levelOfMaxNode1 != levelOfMaxNode2) {
				printf("%d\n", steps / 2);
				continue;
			}
			char colour = ((flag == 0) && levelOfMaxNode1 % 2 == 0) ? 'b' : 'r';
			if(flag == 1 && levelOfMaxNode2 % 2 == 0) {
				colour = 'r';
			} else if(flag == 1 && levelOfMaxNode2 % 2 != 0) {
				colour = 'b';	
			}
			int answer = (str[1] == colour) ? ((steps / 2) + 1) :  (steps / 2);
			printf("%d\n", answer);
		}
	} 
    return 0;
}
