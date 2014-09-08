#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int N, D, i;
	scanf ("%d %d", &N, &D);
	vector <int> length (N + 1);
	for (i = 1; i <= N; i++)
		scanf ("%d", &length [i]);
	sort (length.begin (), length.end ());
	int countPair = 0;
	for (int i = 1; i < N;) {
		if ((length[i + 1] - length[i]) <= D) {
			countPair++;
			i += 2;
		}
		else 
			i++;
	}
	printf("%d\n", countPair);
	return 0;
}