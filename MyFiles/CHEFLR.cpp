#include <cstdio>
#include <vector>
#define MAX 100000

using namespace std;

long long int findNumber (char *str) {
	long long int Num = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (i % 2 == 0 || i == 0) {
			if (str[i] == 'l')
				Num *= 2;
			else
				Num = (Num * 2) + 2; 
		}
		else {
			if (str[i] == 'l')
				Num = (Num * 2) - 1;
			else
				Num = (Num * 2) + 1; 	 
		}
		Num %= 1000000007;
	}
	return Num;
}

int main() 
{
	int T;
	char Str[MAX + 1];
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", Str);
		printf("%lld\n", findNumber (Str));
	}
	return 0;
}