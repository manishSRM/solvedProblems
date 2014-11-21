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
#define MAX 100010

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

VI storeIndex;

int checkPalindrome(char str[], int l, int r) {
	int flag = 1, c = 0;
    for(int i = l; i <= (r + l) / 2; i++) {        
        if(str[i] != str[r - c]) {
        	flag = 0;
        	storeIndex.push_back(i);
        }
        c++;	
    }
    return flag;
}

int checkIndexInsquence() {
	int size = storeIndex.size();
	int temp = storeIndex[0];
	for(int i = 1; i < size; i++) {
		if(temp + i != storeIndex[i])
			return 0;
	}
	return 1;
}

void show() {
	VI :: iterator it = storeIndex.begin();
	for(;it != storeIndex.end(); ++it)
		printf("%d ", *it);
	printf("\n");
}

int main () {
    int T;
    SC(T);
    while(T--) {
    	storeIndex.clear();
    	char str[MAX], C;   
    	scanf("%c%s", &C, str);
    	int count = 0;
    	int r = checkPalindrome(str, 0, strlen(str) - 1);
    	//show();
        if(r) {
    		printf("YES\n");
    		continue;
    	}
        else {
            int leftCheck = checkPalindrome(str, storeIndex[0], strlen(str) - storeIndex[0] - 2);
            int rightCheck = checkPalindrome(str, storeIndex[0] + 1, strlen(str) - storeIndex[0] - 1);
            if(leftCheck & 1 || rightCheck & 1)
                printf("YES\n");
            else 
                printf("NO\n");
        }
    } 
    return 0;
}
