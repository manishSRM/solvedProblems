#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;

char grid[MAX][MAX], str[MAX];
int N;

void input() {
	scanf("%d", &N);
	int row = 1;
	for(int i = 1; i <= N; i++) {
		scanf("%s", str);	
		int column = 1;
		for(int j = 0; str[j] != '\0'; j++)  
			grid[row][column++] = str[j];	
		row++;
	}
}

int main() 
{
	int T;
	scanf("%d", &T);
	while(T--) {
		input();
		int RayFromX [N + 1][N + 1], RayFromY[N + 1][N + 1];
		for(int a = 1; a <= N; a++) {
			for(int b = 1; b <= N; b++)
				RayFromX[a][b] = RayFromY[a][b] = 1;
		}
		for(int i = 1; i <= N; i++) {
			for(int j = N; j >= 1; j--) {
				if(grid[i][j] == '.')
					RayFromX[i][j] = (j != N) ? RayFromX[i][j + 1]:1;
				else
					RayFromX[i][j] = 0;
				
				if(grid[j][i] == '.')
					RayFromY[j][i] = (j != N) ? RayFromY[j + 1][i]:1;
				else
					RayFromY[j][i] = 0;			 
			}
		}
		int maxSum = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(RayFromX[i][j] == 1 && RayFromY[i][j] == 1)
					maxSum++;
			}
		}
		printf("%d\n", maxSum);
	}
	return 0;	
}