#include <iostream>

using namespace std;

int main()
{
	int r, c, i, j, *matrix, mat[10][10];
	cin >> r >> c;
	matrix = new int[r * c]; 
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> matrix[i * c + j];
			mat[i][j] = matrix[i * c + j];

		}
	} 
	cout << "Matrix is :" << "\n";
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Matrix in row major form is = ";
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << matrix[i * c + j] << " ";
		}
	}
	return 0;
}
