#include <cstdio>

using namespace std;

void print_String(char ch[], int m, int n) {
	for(int i = m; i <= n; i++) 
		printf("%c ", ch[i]);
	printf("\n");
}

void print_Substring(char ch[], int l) {
	for(int i = 0; i < l; i++) {
		for(int j = i; j < l; j++) 
			print_String(ch, i, j);
	}
}

int main() {
	char ch[6] = "HELLO";
	print_Substring(ch, 5);
	return 0;
}