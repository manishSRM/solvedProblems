#include<stdio.h>

using namespace std;

int min (int A, int B) {
    if (A < B) return A;
    return B;
}

int count (char str1[], char str2[]) {
	int ar1[128], ar2[128];
	for (int i = 0; i < 128; i++) 
		ar1[i] = ar2[i] = 0;
	for (int i = 0; str1[i] != '\0'; i++)
		ar1[str1[i]]++;
	for (int i = 0; str2[i] != '\0'; i++)
		ar2[str2[i]]++;
	
	int total = 0; 
	for (int i = 0; i < 128; i++)
		total += min (ar1[i], ar2[i]);
	return total; 
}

int main () {
	char str1[10010], str2[10010];
	int r, c;
	scanf ("%d\n", &c);
	for (int j = 0; j < c; j++) {	
		scanf ("%s%s", str1, str2);
		r = count (str1, str2);
		printf ("%d\n", r);	
	}
	return 0;
}
