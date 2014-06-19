#include <cstdio>
#include <string.h>
#define MAX 25000

using namespace std;

void marriageDecision (char big[], char small[], int bigSize, int smallSize) {
	int i, j, a = 0, count = 0;
	for(i =  0; i < smallSize; i++) {
		for(j = a; j < bigSize; j++) {
			if(small[i] == big[j]) {
				a = j + 1;
				count++;
				break;
			}
		}
	}
	if(count == smallSize) 
		printf("YES\n");
	else
		printf("NO\n");
}

int main () {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		char Str1[MAX], Str2[MAX];
		int l1, l2;
		scanf("%s %s", Str1, Str2);
		l1 = strlen(Str1);
		l2 = strlen(Str2);
		if(l1 >= l2)
			marriageDecision(Str1, Str2, l1, l2);
		else
			marriageDecision(Str2, Str1, l2, l1);
	}
	return 0;
}