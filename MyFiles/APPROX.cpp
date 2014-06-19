#include <cstdio>
#define MAX 1000010 

using namespace std;

int A[MAX];

void storeInArray () {
	int R = 4687, Num = 33102;
	for(int i = 0; i < MAX; i++) {          //103993 / 33102 OR 355 / 113
		R *= 10;
		A[i] = R / Num;
		R %= Num;
	}
}

void printArray (int length) {
	if(length == 0) {
		printf("3\n");
		return;
	}
	printf("3.");	
	for(int i = 0; i < length; i++)
		printf("%d", A[i]);
	printf("\n");
}

int main () {
	int T, K;
	scanf("%d", &T);
	storeInArray ();
	for(int i = 0; i < T; i++) {
		scanf("%d", &K);
		printArray (K);
	}
	return 0;
}