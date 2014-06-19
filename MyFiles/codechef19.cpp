#include <cstdio>
#include <iostream>
 
using namespace std;
 
int di[] = {1,1,-1,-1,2,2,-2,-2};
int dj[] = {2,-2,2,-2,1,-1,1,-1};
bool badI[1000];
bool badJ[1000];
bool badDiffY[1000];
bool badDiffX[1000];
bool badSum[2000];
int N;
 
void inputPositionOfQueens(int I[], int J[], int M) {
	int x,y;
 
	for (int i = 0; i < 1000; ++i) {
		badI[i] = badJ[i] = badDiffY[i] = badDiffX[i] = false; 
	}
 
	for (int i = 0; i < 2000; ++i) {
		badSum[i] = false;
	}
 
	for(int i  = 0; i < M; i++)  {
		scanf ("%d %d", &x, &y);
		x--;
		y--;
		I[i] = x;
		J[i] = y;
		badI[x] = true;
		badJ[y] = true;
		if (y>x)
			badDiffY[y-x] = true;
		else
			badDiffX[x-y] = true;
		badSum[x+y] = true;
	}
}
 
bool isValid (int i, int j) {
	if (i>=0 && i<N && j>=0 &&j<N)
		return true;
	return false;
}
 
void findFinalPositions(int I[], int J[], int M) {
 
	int numQueensBeingAttacked[N][N];
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			numQueensBeingAttacked[i][j] = 0;
		}
	}
 
	for (int i = 0; i < M; ++i) {
		int ci = I[i];
		int cj = J[i];
		for (int dir=0; dir<8; ++dir) {
			int ni = ci + di[dir];
			int nj = cj + dj[dir];
			if (isValid(ni,nj)) {
				numQueensBeingAttacked[ni][nj]++;			
			}
		}
	}
	int goodPositions = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (numQueensBeingAttacked[i][j] >= 2) {
				if (badI[i] || badJ[j] || badSum[i+j])
					continue;
				if ((i<j && badDiffY[j-i]) || (i>=j && badDiffX[i-j]))
					continue;
				goodPositions++;
			}
		}
	}
	cout<<goodPositions<<endl;
}
 
void test_Cases(int T) {
	for (int i = 0; i < T; ++i) {
		int M;
		scanf("%d %d", &N, &M);
		int I[M], J[M];
		inputPositionOfQueens(I, J, M);
		findFinalPositions(I, J, M);
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	test_Cases(T);
	return 0;
}
