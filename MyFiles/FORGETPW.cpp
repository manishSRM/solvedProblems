#include <cstdio>
#include <string.h>
#define MAX 1000010
#define N_MAX 110

using namespace std;

char C[N_MAX], P[N_MAX];
bool check[MAX];

void initalizeBoolArray (int size) {
	for(int i = 0; i < size; i++) 
		check[i] = false;
}

void inputRules (int size) {
	char temp[2], temp2[2];
	for (int i = 0; i < size; i++) {
		scanf ("%s %s", temp, temp2);
		C[i] = temp[0];
		P[i] = temp2[0];
	}
	return;
}

void changeString (char str[], int size_ruleStrings) {
	for (int i = 0; i < size_ruleStrings; i++) {
		for (int j = 0; str[j] != '\0'; j++) {
			if ((C[i] == str[j]) && (check[j] != true)) {
				str[j] = P[i];
				check[j] = true;
			}	
		}
	}
	return;
}

int findStartingIndex (char s1[]) {
	int i;
	for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != 48)
            break; 
    }
    return i;
}

int findEndIndex (char s2[]) {
	int i;
	for (i = strlen (s2) - 1; i >= 0; i--) {
        if (s2[i] != 48) 
            break;
    }
    return i;
}

int main () {
	int T, N, end, c;
	scanf ("%d", &T);
	char string[MAX];
	for (int i = 1; i <= T; i++) {
		scanf ("%d", &N);
		inputRules (N);
		scanf ("%s", string);
		int len = strlen(string);
		initalizeBoolArray (len);
		changeString (string, N);
		int c1 = 0;
		for (int d = 0; d < len; d++) {
			if (string[d] == '0' || string[d] == '.') 
				c1++;
		}
		if (c1 == len) {
			printf("0\n");
			continue;
		}
		int start = findStartingIndex (string);
		for (c = 0; string[c] != '\0'; c++) {
			if (string[c] == '.')
				break;
		}
		if (string[c] == '\0')
			end = c - 1;
		else
			end = findEndIndex (string);
		if (string[end] == '.')
			end -= 1;
		for (int j = start; j <= end; j++) {
			printf("%c", string[j]);
		}	
		printf("\n");	 
	}
	return 0;
}