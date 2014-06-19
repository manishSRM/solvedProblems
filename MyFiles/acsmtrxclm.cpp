#include<iostream>

	using namespace std;

	int main()
	{
		int r, c, i, j, *matrix, mat[10][10];
		cin >> r >> c;
		matrix = new int[r * c]; 
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				cin >> matrix[j * r + i];
				mat[i][j] = matrix[j * r + i];
			}
		}
		cout << "Matrix is :" << "\n";
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				cout << mat[i][j] << " ";
			}
			cout << "\n";
		}
	
		cout << "Matrix in coulmn major form is = ";
		for (i = 0; i < r; i++) {
			//for (j = 0; j < c; j++) {
				cout << matrix[i] << " ";
			//}
		}
		return 0;
	}
