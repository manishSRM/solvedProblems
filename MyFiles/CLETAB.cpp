#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

int findIndex (const vector<int> &orders, int start, int end, int element) {
    for (int i = start; i <= end; i++) {
        if (orders[i] == element)
            return i;
    }
    return 0;
}

int main () {
	int T; 
	scanf ("%d", &T);
	while (T--) {
		int N, M;
		scanf ("%d %d", &N, &M);
		vector<int> orders (M + 1);
		for (int i = 1; i <= M; i++) 
			scanf ("%d", &orders[i]);
		
		vector <int> tables (N + 1, 0);
		vector<bool> check (401, false);
		int c = 0, j, maxCount = 0;

		for (j = 1; j <= M; j++) {
			if (maxCount == N)
				break;
			if (check[orders[j]] == false) {
				check[orders[j]] = true;
				tables[++c] = orders[j];
				maxCount++;
			}
		}
		for (; j <= M; j++) {
		    int goodIndex = INT_MIN, pos, index;
		    if (check[orders[j]] == true)
		        continue;
			for (int k = 1; k <= N; k++) {
			    index = findIndex (orders, j + 1, M, tables[k]);
			    if (index == 0) {
			        check[tables[k]] = false;
			        tables[k] = orders[j];
			        check[orders[j]] = true;
			        maxCount++;
			        break;
			    }
			    if (goodIndex < index) {
			        goodIndex = index;
			        pos = k;
			    }
			}
			if (index != 0) {
			    check[tables[pos]] = false;
			    tables[pos] = orders[j];
			    check[orders[j]] = true;
			    maxCount++;
			}
 		}
 		printf("%d\n", maxCount);
 	}	
	return 0;
}