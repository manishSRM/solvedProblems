#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int GCD (int num1, int num2) {
	if (num1  < num2)
		swap (num1, num2);
	while (num2) {
		int r = num1 % num2;
		num1 = num2;
		num2 = r;
	}
	return num1;
}

int main () {
	int T, N;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &N);
		vector <int> ingredients (N + 1);
		for (int i = 1; i <= N; i++)
			scanf ("%d", &ingredients[i]);
		int gcd = GCD (ingredients[1], ingredients[2]);
		for (int j = 3; j <= N; j++) 
			gcd = GCD (gcd, ingredients[j]);
		if (gcd != 1) {
			for (int k = 1; k <= N; k++) 
				printf("%d ", ingredients[k] / gcd);
		}
		else {
			for (int k = 1; k <= N; k++) 
				printf("%d ", ingredients[k]);
		}
		printf("\n");
	}
	return 0;
}