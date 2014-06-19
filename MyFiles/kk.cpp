#include <stdio.h>
#include <algorithm>

using namespace std;

int X (int n) {
	if (n % 2 == 0)
		return 0;
	else 
		return 1;
} 

int main() {
	int a = 5;
	//X(a);
	printf ("%d\n", X(a));
	return 8;
}
