#include <cstdio>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

int findLongestCommonPrefix (char first[], char second[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (first[i] != second[i])
			break;
	}
	return i;
} 

void rotateString (char second[], int parent[], int size) {
	int i = 0;
	char temp = second[0];
	for (int j = 0; j < size; j++) 
		second[j] = second[parent[i++]];
	second[size - 1] = temp;
}

int main () {
	int N, temp = INT_MIN, oldTemp = INT_MIN, count = 0, maxRotation = 0;
	scanf ("%d", &N);
	char first[N], second[N];
	int parent[N];
	scanf ("%s", first);
	scanf ("%s", second);
	
	for (int i = 0; i < N; i++) 
		parent[i] = i + 1;
	parent[N - 1] = 0;
	
	temp = findLongestCommonPrefix (first, second, N);
	
	if (oldTemp < temp) 
		oldTemp = temp;
	if (oldTemp == N) {
		printf("0\n");
		return 0;
	}
	for (int j = 0; j < N; j++) {	
		rotateString (second, parent, N);
		++count;
		temp = findLongestCommonPrefix (first, second, N);
		if (oldTemp < temp) {
			oldTemp = temp;
			maxRotation = count;
		} 				 
	}
	if (N == 1 && (first[0] != second[0]))
		maxRotation = 0; 
	printf("%d\n", maxRotation);
	return 0;	
}