#include <cstdio>
#include <string.h>
#define MAX 100005

using namespace std;

int main() 
{
	int T;
	char str[MAX];
	scanf ("%d", &T);
	while(T--) {
		int answer = 1;
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; i++) {
			if(str[i] != str[len - i - 1])
				answer = 2;
		}
		printf("%d\n", answer);
	}
	return 0;
} 