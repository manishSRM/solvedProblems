#include<stdio.h>
#include<math.h>

using namespace std;

void snape(int B, int LS, float *min, float *max) {
	*max = sqrt(LS * LS + B * B);
	*min = sqrt(LS * LS - B * B);
}

void test_Cases(int T) {
	int LS, B;
	float min, max;
	for(int i = 0; i < T; i++) {
		scanf("%d %d", &B, &LS);
		snape(B, LS, &min, &max);
		printf("%0.5f %0.5f\n", min, max);
	}
	printf("\n"); 
}

int main() {
	int t;
	scanf("%d", &t);
	test_Cases(t);
	return 0;
}
