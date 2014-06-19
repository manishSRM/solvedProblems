#include <stdio.h>

using namespace std;

int main() {
	int x = 1, a = 10, b = 5;
	//b = (a = a + 10) * (a + 5);
	printf("%d\n", (a = a + 10) * (a + 5));
	return 0; 
}
