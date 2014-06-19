#include <cstdio>
#include <iostream>

using namespace std;

int matrix[100][100];
int cache[100][100];
int size;

void input_Matrix (int l) {
	for(int i = 0; i < l; i++) {
		for(int j = 0; j <= i; j++)
			scanf("%d", &matrix[i][j]);
	}
}

void initialize_Cache(int l) {
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++)
			cache[i][j] = 0;
	}
}

int solve(int i, int j) {
	if(i >= size)
		return 0;
	if(cache[i][j] != 0)
		return cache[i][j];
	int t1 = solve(i + 1, j);
	int t2 = solve(i + 1, j + 1);
	cache[i][j] = max(t1, t2) + matrix[i][j];
	return cache[i][j];
}

void test_Cases(int T) {
	for(int i = 0; i < T; i++) {
		scanf("%d", &size);
		input_Matrix(size);
		initialize_Cache(size);
		printf("%d\n", solve(0, 0));
	}
}

int main () {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}