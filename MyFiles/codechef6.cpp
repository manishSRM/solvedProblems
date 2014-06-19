#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

#define _N_MAX 100010

using namespace std;

int int_abs(int temp) {
	if(temp < 0)
		return temp *= -1;
	return temp;
}

void X(int ans[], int count[], int A[], int n) {
	int j;
	for (int i = 0; i < n; i++) {
    	int currentNum = A[i]; 
    	ans[i] = 0;
    	for (j = 0; j < 10; j++) {
    	    ans[i] += count[j] * int_abs(currentNum - j);
   		}
    	count[currentNum]++;
	}
}

int main() {
	int t, size, temp, ans[_N_MAX], array[_N_MAX], count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char char_array[_N_MAX];
	
	scanf("%d %d", &size, &t);
	scanf("%s", char_array);

	for (int i = 0;  char_array[i] != '\0'; i++) {
	    array[i] = char_array[i] - '0';
	}
	X(ans, count, array, size);
	for(int i = 1; i <= t; i++) {
		scanf("%d", &temp);
		printf("%d\n", ans[temp - 1]);
	}
	return 0;
}
