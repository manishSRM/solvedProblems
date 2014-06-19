#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <iostream>

#define MAX 100000

using namespace std;

int matchsticksBuringTime[MAX];
int N;

void input_BurningTime (int l) {
	for (int i = 0; i < l; i++) 
		scanf("%d", &matchsticksBuringTime[i]);
}

int maximumValue(int l, int r) {
	int temp = 0;
	for (int i = l; i <= r; i++) {
		temp = max (temp, matchsticksBuringTime[i]);
	}
	return temp;
}

int minimumValue(int l, int r) {
	int temp = INT_MAX;
	for (int j = l; j <= r; j++) {
		temp = min (temp, matchsticksBuringTime[j]);
	}
	return temp;
}

void quries (int Q) {
	int L, R, max1, min1, max2;
	float ans;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &L, &R);
		max1 = maximumValue(L, R);
		min1 = minimumValue(L, R);
		max2 = max (maximumValue(0, L-1), maximumValue(R+1, N-1));
		
		printf("%d %d %d\n", min1, max1, max2);
		float ans1 = max2;
		float ans2 = (max1 - min1) / 2.0;
		ans = min1 + max (ans1, ans2);
		printf("%0.1f\n", ans);
	}
}

int main() {
	int Q;
	scanf("%d", &N);
	input_BurningTime(N);
	scanf("%d", &Q);
	quries(Q);
	return 0;
}