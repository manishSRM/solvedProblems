#include <cstdio>

using namespace std;

#define MAX 100001

int A[MAX][MAX];

void input_Matrix(int n, int m) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) 
			A[i][j] = j;
	}
	return;
}

void update_Matrix(int p) {
	int i, j;
	for(int k = 0; k < p; k++) {
		scanf("%d %d", &i, &j);
		A[i][j]++;
	}
}

void print_Matrix(int n, int m) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) 
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int trave_Row(int i, int m) {
	int sum = 0, s1;
	for(int k = m; k >= 2; k--) {
		s1 = A[i][k] - A[i][k - 1];
		if(s1 >= 0)
			sum += s1;
		else 
			return -1;
	}
	return sum;
}

void travel_Matrix(int n, int m) {
	for(int i = 1; i <= n; i++) {
		int r = trave_Row(i, m);
		printf("%d\n", r);
	}
}

int main() {
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	input_Matrix(n, m);
	update_Matrix(p);
	travel_Matrix(n, m);
	//print_Matrix(n, m);
	return 0;
}
