#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int countCycles (vector<bool> &CHECK , int N,  const vector <int> &P) {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (CHECK[i] == true)
			continue;
		count++;
		CHECK[i] = true;
		for (int j = P[i]; j <= N;) {
			if (CHECK[j] == true)
				break;
			CHECK[j] = true;
			j = P[j];
		}		
	}
	return count;
}

void printCycles (vector <bool> &CHECK2, int N, const vector <int> &P) {
	for (int i = 1; i <= N; i++) {
		if (CHECK2[i] == true)
			continue;
		CHECK2[i] = true;
		printf("%d ", i);
		for (int j = P[i]; j <= N;) {
			printf("%d ", j);
			if (CHECK2[j] == true)
				break;
			CHECK2[j] = true;
			j = P[j];
		}
		printf("\n");		
	}
}

int main () {
	int N;
	scanf ("%d", &N);
	vector <int> P (N + 1);
	for (int i = 1; i <= N; i++) 
		scanf ("%d", &P[i]);
	vector <bool> CHECK (N + 1, false);
	printf("%d\n", countCycles (CHECK, N, P));
	vector <bool> CHECK2 (N + 1, false);
	printCycles (CHECK2, N, P);
	return 0;
}