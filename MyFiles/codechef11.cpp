#include<stdio.h>
#include<string.h>

using namespace std;

int count_Holes(char str[], int len) {
	int i = 0, count = 0;
	while(str[i] != '\0') {
		if(str[i] == 'A' || str[i] == 'B' || str[i] == 'D' || str[i] == 'O' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R') {
			if(str[i] == 'B')
				count += 2;
			else 
				count++; 
		}
		i++;
	}
	return count;
}

void test_Cases(char str[], int T) {
	int l;
	for(int i = 0; i < T; i++) {
		scanf("%s", str);
		l = strlen(str);
		printf("%d\n", count_Holes(str, l));
	}
}

int main() {
	char str[100];
	int t;
	scanf("%d", &t);
	test_Cases(str, t);		
	return 0;
}
