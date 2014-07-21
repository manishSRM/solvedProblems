#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int checkInColumn (int element, int matrix[3][3], int column) {
	for (int i = 0; i < 3; i++) {
		if (element < matrix[i][column])
			return 0;
	}
	return 1;
}

int checkInRow (int element, int matrix[3][3], int row) {
	for (int j = 0; j < 3; j++) {
		if (element > matrix[row][j])
			return 0;
	}
	return 1;
}

void checkSaddlePoint (int matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int result = checkInColumn (matrix[i][j], matrix, j);
			if (result) {
				int result2 = checkInRow (matrix[i][j], matrix, i);
				if (result2)
					printf("%d ", matrix[i][j]);
				else
					break;
			}	
		}
	}
}

int main () {
	int matrix[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			scanf ("%d", &matrix[i][j]);
	}
	checkSaddlePoint (matrix);
	return 0;
}