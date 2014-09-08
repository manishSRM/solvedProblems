#include <cstdio>
#include <vector>

using namespace std;

int main () {
	int T;
	char string[201];
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", string);
		vector <int> countCharacter (125, 0);
		for (int i = 0; string[i] != '\0'; i++) 
			countCharacter[string[i]]++;
		int maxCount = 0;
		for (int j = 65; j < 124; j++) {
			//printf("%d %d\n", countCharacter[j], j);
			if (countCharacter[j] != 0) {
				if (countCharacter[j] % 2 == 0)
					maxCount += countCharacter[j] / 2;
				else
					maxCount += countCharacter[j] / 2 + 1;
			}
		}
		printf("%d\n", maxCount);
	}
	return 0;
}