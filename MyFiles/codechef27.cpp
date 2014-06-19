#include <cstdio>
#define MAX 100000

using namespace std;

int matchsticksBuringTime[MAX];
float newBuringTimeOfMatchstics[MAX];

int N;

void input_BurningTime (int l) {
	for (int i = 0; i < l; i++) 
		scanf("%d", &matchsticksBuringTime[i]);
}

int findIndexOfLowestBuringTime (int l, int r) {
	int temp, index;
	temp = matchsticksBuringTime[l];
	index = l;
	for (int i = l + 1; i <= r; i++) {
		if(temp > matchsticksBuringTime[i]) {
			temp = matchsticksBuringTime[i];
			index = i;
		}	
	}
	return index;
}

void newBuringTime(int L, int R) {
	int index, temp;
	index = findIndexOfLowestBuringTime(L, R);
	for(int i = 0; i <= N - 1; i++) {
		if(i < L || i > R)
			newBuringTimeOfMatchstics[i] = matchsticksBuringTime[i] + matchsticksBuringTime[index];
		else if(i == index)
			newBuringTimeOfMatchstics[i] = matchsticksBuringTime[i];
		else {
			temp = matchsticksBuringTime[i] - matchsticksBuringTime[index];
			newBuringTimeOfMatchstics[i] = matchsticksBuringTime[index] + temp / 2.0;
		}
	}
}

float largestBuringTime () {
	float temp;
	temp = newBuringTimeOfMatchstics[0];
	for (int i = 1; i < N; i++) {
		if(temp < newBuringTimeOfMatchstics[i])
			temp = newBuringTimeOfMatchstics[i];
	}
	return temp;
}

void quries (int Q) {
	int L, R;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &L, &R);
		newBuringTime(L, R);
		printf("%0.1f\n", largestBuringTime());
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