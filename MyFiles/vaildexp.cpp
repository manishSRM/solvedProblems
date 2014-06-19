#include <cstdio>
#include <string.h>

using namespace std;

int check_Valid(char ch[]) {
	int count = 0, i = 0;
	while(ch[i] != '\0') {
		if(ch[i] == '(')
			count += 1;
		else
			count -= 1;
		if(count < 0) 
			return 0;
		i++;					
	}
	if(count != 0)
		return 0;
	return 1;
}

int main() {
	char ch[100];
	scanf("%s", ch);
	printf("%d\n", check_Valid(ch));
	return 0;
}