#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

#define _DEBUG 1

#if _DEBUG

#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

int B[260];
char b[260];
int r;

void input_Array (int l) {
	for(int i = 0; b[i] != '\0'; i++) 
		B[i] = b[i] - '0';	
}	

int countdigit (int num) {
	trace1 (num);
	int i = 0;
	while(num) {	
		i++;
		r = num % 10;
		num /= 10;
		trace2 (r, num);
	}
	trace1 (r)
	return i;
}

int divideNumbers (int num, int len) {
	int count = countdigit (num);
	return 0;
}

void testCases (int T) {
	for (int i = 0; i < T; i++) {
		int A, size, remain;
		scanf("%d %s", &A, b);
		size = strlen(b);
		input_Array(size);
		remain = divideNumbers(A, size); 
	}
}

int main () {
	int t;
	scanf("%d", &t);
	trace1 (t);
	printf("\n%d %d\n", countdigit(t), r);
	//testCases(t);
	return 0;
}