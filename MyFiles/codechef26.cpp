#include <cstdio>
#include <string.h>
#include <iostream>

#define MAX 1000001

using namespace std;

char ch[MAX];

int findLengthOfPrefix(int l) {
	int count = 0, i, ans = 0;
	for(i = 0; ch[i] != '\0'; i++) {
		if(ch[i] == '<') 
			count += 1;
		else
			count -= 1;
		if(count < 0)
			return ans;
		if (count == 0)
		    ans = i + 1;
	}
	if(count == 0)
		ans = i;
	return ans;
}

void test_Cases(int T) {
	for(int i = 0; i < T; i++) {
		scanf("%s", ch);
		int l = strlen(ch);	
		int r = findLengthOfPrefix(l);
		printf("%d\n", r);
	}
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	test_Cases(T);
	return 0;
}