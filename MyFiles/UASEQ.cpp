#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>  
#include <stack>
#include <set>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
#include <cstdlib>
#define lint long long int
#define FOR(A, B, C) for (int A = B; A < C; A++) 
#define EFOR(A, B, C) for (int A = B; A <= C; A++)
#define RFOR(A, B, C) for (int A = B; A >= C; A--)

using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef set<PI> setPI;
typedef vector<lint> VLI;
typedef vector<VI> VII;
typedef vector<bool> VBI;

setPI differcncePirs;

void generate_ai_bi_Pairs (const VI &A, int N) {
	int ai, bi, n = 0;
	EFOR(j, 1, N - 1) {
		bi = A[j + 1] - A[j];
		ai = A[j] - (n++ * bi);
		differcncePirs.insert (make_pair(ai, bi));
	}
}

void calculate_K (const VI &A, int N, int K) {
	int best_a0 = INT_MAX, best_b0 = INT_MAX;
	for (setPI::iterator iter = differcncePirs.begin(); iter != differcncePirs.end(); ++iter) {
		int a0 = iter -> first;
		int b0 = iter -> second;
		if (best_a0 > a0 || (best_a0 == a0 && best_b0 > b0)) {	
			int temp, n = 0, K1 = 0;
			EFOR(j, 1, N) {
				temp = a0 + (n++ * b0);
				if (temp != A[j])  
					K1++;
			}
			if (K1 <= K) {
				best_a0 = a0;
				best_b0 = b0;	
			}	
		}
	}
	int n = 0;
	EFOR(k, 1, N) 
		printf("%d ", best_a0 + ((n++) * best_b0));
	printf("\n");	
}

int main ()
{
	int N, K;
	scanf ("%d%d", &N, &K);
	VI A(N + 1);
	EFOR(i, 1, N)
		scanf ("%d", &A[i]);
	generate_ai_bi_Pairs (A, N);
	calculate_K (A, N, K);
	return 0;
} 