#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(A, B, C) for(int A = B; A < C; A++)
#define EFOR(A, B, C) for(int A = B; A <= C; A++)
#define RFOR(A, B, C) for(int A = B; A >= C; A--)
#define MAX 100000

using namespace std;

vector <int> A (MAX + 1);

int N, M;

int main () 
{
	char C, C1;
	int d, current_Rotation = 0;
	scanf ("%d%d", &N, &M);
	EFOR (i, 1, N) 
		scanf ("%d", &A[i]);	
	FOR(j, 0, M) {
		scanf ("%c%c%d", &C1, &C, &d);
		if (d > N) 
			d %= N;
		if (C == 'C') 
			current_Rotation += d;
		else if (C == 'A')
			current_Rotation += N - d;
		else { 
			if (current_Rotation > N) 
				current_Rotation %= N;
			if (d + current_Rotation > N)
				printf("%d\n", A[d + current_Rotation - N]);
			else
				printf("%d\n", A[d + current_Rotation]);
		}			
	}	
	return 0;
}