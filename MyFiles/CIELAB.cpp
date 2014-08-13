#include <cstdio>

using namespace std;

int main () {
	int A, B;
	scanf ("%d %d", &A, &B);
	int dif = A - B;
	if (dif % 10 != 9) 
		printf("%d\n", dif + 1);
	else
		printf("%d\n", dif - 1);
	return 0;
}