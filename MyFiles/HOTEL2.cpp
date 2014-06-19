#include <cstdio>
#include <algorithm>

using namespace std;

struct event {
	int eventTime;
	int isArrival;
} allEvents[2200];

int cmp(const event &A, const event &B) {
	if(A.eventTime < B.eventTime)
		return 1;
	if(A.eventTime == B.eventTime && A.isArrival == 0 && B.isArrival == 1)
		return 1;
	return 0;
}

void initialize(int l) {
	int i = 0;
	for(; i < l; i++) {
		scanf("%d", &allEvents[i].eventTime);
		allEvents[i].isArrival = 1;
	}
	for(; i < 2 * l; i++) {
		scanf("%d", &allEvents[i].eventTime);
		allEvents[i].isArrival = 0;
	}
	sort(allEvents, allEvents + 2 * l, cmp);
}

int countMans(int l) {
	int count = 0, max_count = 0, c = 0;
	for(int k = 0; k < 2 * l; k++) {
		if(allEvents[k].isArrival == 1)
			count++;
		else
			count--;
		max_count = max (max_count, count);
	}
	return max_count;
}

void testCases(int T) {
	for(int i = 0; i < T; i++) {
		int len, max;
		scanf("%d", &len);
		initialize(len);
		printf("%d\n", countMans(len));
	}
}

int main() {
	int t;
	scanf("%d", &t);
	testCases(t);
	return 0;
}