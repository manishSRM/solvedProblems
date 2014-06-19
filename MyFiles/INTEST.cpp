#include <cstdio>
#define MAX 10000000

using namespace std;

int main () {
	int T, K, num, count = 0;;
	scanf("%d %d", &T, &K);
	for(int i = 0; i < T; i++) {
		scanf("%d", &num);
		if(num % K == 0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}