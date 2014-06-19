#include <stdio.h>
#include <algorithm>

using namespace std;

void evenOdd(int s[], int g) {
	int a;
	for(int i = 0; i < g; i++) { 
		a = i;
		for(int j = a - 1; j >= 0; j--) {
			if(s[j] % 2 == 0) {
				swap (s[a], s[j]);
				a--;
			}
			else
				break;
		}	
	}
}

int main() {
	int a[] = {1, 2, 4, 5, 6, 5}, n = 6, i;
	evenOdd(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
	
}

