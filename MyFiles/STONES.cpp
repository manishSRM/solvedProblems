#include <cstdio>
#include <string.h>

using namespace std;

void findCommonTerms (char *S, char *J) {
	int count = 0;
	for (int i = 0; S[i] != '\0'; i++) {
		for (int j = 0; J[j] != '\0'; j++) {
			if (S[i] == J[j]) {
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);
}
 
int main () {
	int T;
	char c;
	char J[110], S[110];
	scanf ("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf ("%s%s", J, S); 
		findCommonTerms (S, J);
	}
	return 0;
}