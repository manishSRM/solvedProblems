#include <cstdio>

using namespace std;

struct event {
	int hour;
	char ch;
	int minute;
} girl_Time, chef_Time;


float firstCase (int t1) {
	float difference;
	int temp;
	temp = ((girl_Time.hour - chef_Time.hour) * 60 + (girl_Time.minute - chef_Time.minute));
	difference = float(temp + t1);
	return difference;
}

float secondCase (int t2) {
	int temp;
	float temp2;
	temp = ((girl_Time.hour - chef_Time.hour) * 60 + (girl_Time.minute - chef_Time.minute));
	if(2 * t2 <= temp)
		return float(temp);
	temp2 = float((2 * t2 - temp) / 2.0f + temp);
	return temp2;
}

int main () {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int timeToBus;
		scanf("%d%c%d", &girl_Time.hour, &girl_Time.ch, &girl_Time.minute);
		scanf("%d%c%d", &chef_Time.hour, &chef_Time.ch, &chef_Time.minute);
		scanf("%d", &timeToBus);
		printf("%0.1f ", firstCase(timeToBus));
		printf("%0.1f\n", secondCase(timeToBus));
	}
	return 0;
}