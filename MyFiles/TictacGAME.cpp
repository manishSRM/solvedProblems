#include <cstdio>
#include <algorithm>
#include <iostream>
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
typedef vector<vector<int> > VII;
typedef vector<vector<pair<int,int> > > VVPI;
typedef vector<string> VS;

void setdashpattern(int row, VII &matrix) {
	EFOR(i, 1, 13) {
		if(i == 1 || i == 5 || i == 9 || i == 13)
			matrix[row][i] = '*';
		else
			matrix[row][i] = '-';
	}
}

void setVerticalPattern(int row, VII &matrix) {
	EFOR(i, 1, 13) {
		if(i == 1 || i == 5 || i == 9 || i == 13)
			matrix[row][i] = '|';
		else
			matrix[row][i] = ' ';	
	}
}

void initializeMatrix(VII &matrix, int size) {
	EFOR(i, 1, size) {
		if(i % 2) {
			setdashpattern(i, matrix);
		} else {
			setVerticalPattern(i, matrix);
		}
	}
}

void displayStausOfGame(const VII &matrix, int s1, int s2) {
	EFOR(i, 1, s1) {
		EFOR(k, 1, 6) {
			printf(" ");
		}
		EFOR(j, 1, s2) 
			printf("%c", matrix[i][j]);
		printf("\n");
	}
}

void initializeInputMatrix(vector<vector<pair<int,int> > > &A, int N) {
	vector<pair<int,int> > B(N);
	B[1] = (make_pair(2, 3));
	B[2] = (make_pair(2, 7));
	B[3] = (make_pair(2, 11));
	A[1] = B;
	B[1] = (make_pair(4, 3));
	B[2] = (make_pair(4, 7));
	B[3] = (make_pair(4, 11));
	A[2] = B;
	B[1] = (make_pair(6, 3));
	B[2] = (make_pair(6, 7));
	B[3] = (make_pair(6, 11));
	A[3] = B;
}

int leftDiagonalComplete(const VII &M, int N) {
	int c = M[1][1];
	EFOR(i, 2, N) {
		if(c != M[i][i])
			return 0;
	}
	return 1;
}

int rightDiagonalComplete(const VII &M, int N) {
	int c = M[1][N];
	EFOR(i, 2, N) {
		if(c != M[i][(N + 1) - i])
			return 0;
	}
	return 1;
}

int rowXComplete(int row, const VII &M, int N) {
	int temp = M[row][1];
	EFOR(j, 2, N) {
		if(temp != M[row][j])
			return 0;
	}
	return 1;
}

int columnYComplete(int column, const VII &M, int N) {
	int temp = M[1][column];
	EFOR(i, 2, N) {
		if(temp != M[i][column])
			return 0;
	}
	return 1;
}

inline int pointOnleftDiagonal(int x, int y) {
	return (x == y) ? 1 : 0;
}

inline int pointOnRightDiagonal(int x, int y, int N) {
	return ((x + y) == (N + 1) ? 1 : 0);
}

int anyBodyWinOrNot(const VII &M, int x, int y, int N) {
	if(pointOnleftDiagonal(x, y) && leftDiagonalComplete(M, N)) {
		return 1;
	}

	if(pointOnRightDiagonal(x, y, N) && rightDiagonalComplete(M, N)) {
		return 1;
	}
	
	if(rowXComplete(x, M, N)) {
		return 1;		
	}
	if(columnYComplete(y, M, N)) {
		return 1;
	}
	return -1;	
}

void changeIndex(int &index, int k) {
	index ^= (1 << k);
}

void showResultMatrix(const VII &M) {
	EFOR(i, 1, 3) {
		EFOR(j, 1, 3) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

int getPlayerNames(vector<string> &V, int N) {
	char player1[15], player2[15];
	printf("\nENTER THE NAMES OF THE PLAYERS : \n");
	scanf("%s", player1);
	scanf("%s", player2);
	V.push_back(player1);
	V.push_back(player2);
	srand(time(NULL));
	int randomPlayerIndex = rand() % (N - 2);
	printf("%s YOUR FIRST TURN\n", V[randomPlayerIndex].c_str());
	return randomPlayerIndex;
}

PI ifLastChancePossible(const VII &M, int N) {
	EFOR(i, 1, N) {
		EFOR(j, 1, N) {
			if(M[i][j] == -1) {
				return (make_pair(i, j)); 
			}
		}
	}
} 

void lastTurnWinOrTie(VII &S, VII &R, VVPI &I, int secretIndex, int N, int &isWinnerDecided, const VS &V) {
	PI myPair = ifLastChancePossible(R, (N - 1));
	S[I[myPair.first][myPair.second].first][I[myPair.first][myPair.second].second] = 'X';
	displayStausOfGame(S, 7, 13);
	R[myPair.first][myPair.second] = 1;
	int gameResult = anyBodyWinOrNot(R, myPair.first, myPair.second, (N - 1));
	if(gameResult != -1) {
		cout << V[secretIndex] << " WIN!!\n";
		isWinnerDecided = 1;
	}
	return;
}

int main() {
	VII statusMatrix(8, vector<int>(14));
	initializeMatrix(statusMatrix, 7);
	printf("\n********************** THIS IS TIC-TAC-TOE GAME ******************************\n");
	displayStausOfGame(statusMatrix, 7, 13);
	int N = 4;
	VVPI inputmatrix(N);
	initializeInputMatrix(inputmatrix, N);
	VII resultMatrix(N, vector<int>(N, -1));
	VS V;
	int randomPlayerIndex = getPlayerNames(V, N);
	int counter = 1, isWinnerDecided = 0, flag2 = 0, temp = randomPlayerIndex;
	while(counter < 9) {
		int x, y;
		if(counter != 1 && flag2 != 1) {
			changeIndex(randomPlayerIndex, 0);
			cout << V[randomPlayerIndex] << "'s TURN\n";
		}
		printf("ENTER THE ROW && COLUMN No. ");
		SC(x); SC(y);
		if(resultMatrix[x][y] != -1) {
			printf("THIS SLOT IS ALREADY FIXED TRY ANYTHING ELSE!\n");
			cout << "AGAIN " << V[randomPlayerIndex] << "'s TURN\n"; 
			flag2 = 1;
			continue;
		}
		resultMatrix[x][y] = (counter % 2) ? 1 : 0;
		if(counter % 2) {
			statusMatrix[inputmatrix[x][y].first][inputmatrix[x][y].second] = 'X';
		} else {
			statusMatrix[inputmatrix[x][y].first][inputmatrix[x][y].second] = '0';
		}
		displayStausOfGame(statusMatrix, 7, 13);
		int result = anyBodyWinOrNot(resultMatrix, x, y, (N - 1));
		if(result != -1) {		
			if(!resultMatrix[x][y]) {
				changeIndex(temp, 0);
				cout << V[temp] << " WIN!!\n";
				isWinnerDecided = 1;
				break;
			} else {
				cout << V[temp] << " WIN!!\n";
				isWinnerDecided = 1;
				break;
			}
		}
		counter++;
	}
	if(!isWinnerDecided)
		lastTurnWinOrTie(statusMatrix, resultMatrix, inputmatrix, temp, N, isWinnerDecided, V);
	if(!isWinnerDecided) { 
		printf("MATCH TIE!!\n");
	}
	return 0;
}