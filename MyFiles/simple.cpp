#include <stdio.h>

using namespace std;

int main() {
	int c;
	c = getchar();
	while(c != EOF) {
		putchar(c);
		c = getchar();
	}	
	return 0;
}
