#include <cstdio>
#define MAX 100010

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		char string[MAX];
		int size;
		scanf ("%d", &size);
		scanf ("%s", string);
		int count = 0;
		long long int maxCount = 0;
		for (int i = 0; i < size; i++) {
			if (string[i] == '1') {
				maxCount += count + 1;
				count++;
			}
		}
		printf("%lld\n", maxCount);
	}
	return 0;
}