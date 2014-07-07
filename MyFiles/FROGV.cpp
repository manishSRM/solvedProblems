#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(A, B, C) for (int A = B; A < C; A++)
#define RFOR(A, B, C) for (int A = B; A >= C; A--)
#define EFOR(A, B, C) for (int A = B; A <= C; A++)
#define PB(B) push_back(B)

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector <II> VII;

int cmp (const II &a, const II &b) {
	return a.first < b.first;
}

void initalizeArrayOfstoreIndex (VI &c, const VII &b, int size) {
	EFOR (k, 1, size)
		c[b[k].second] = k;
}

void initalizeMaxRightArray (VI &maxRight, const VII &A, int size, int limit) {
	maxRight[size] = size;
	RFOR(i, size - 1, 1) {
		if (A[i].first + limit >= A[i + 1].first)
		    maxRight[i] = maxRight[i + 1];
		else
			maxRight[i] = i;
	}
}

int main () {
	int N, K, P;
	scanf ("%d %d %d", &N, &K, &P);

	VI co_ordinate (N + 1);
	VII B(N + 1);
	VI C(N + 1);
	VI maxRight(N + 1);

	EFOR(i, 1, N) {
		scanf ("%d", &co_ordinate[i]);
		B[i] = II(co_ordinate[i], i);
	}

	sort (B.begin() + 1, B.begin() + N + 1, cmp);
	initalizeArrayOfstoreIndex (C, B, N);
	initalizeMaxRightArray (maxRight, B, N, K);

	EFOR(j, 1, P) {
		int A, B;
		scanf ("%d %d", &A, &B);
        A = C[A];
        B = C[B];
        if (A > B)
        	swap (A, B);
        if (maxRight[A] >= B)
        	printf("Yes\n");
        else
        	printf("No\n");
	}
	return 0;
}
