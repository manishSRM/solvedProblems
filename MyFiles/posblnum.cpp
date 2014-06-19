#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a, b, c, i;
	cin >> a >> b >> c;
	for (i = 1; i < 4; i++) {
		cout << a * 100 + b * 10 + c << "   ";
		cout << a * 100 + c * 10 + b << "   ";
		if (i % 2 != 0 && i + 2 == 3)
			swap (a, b);
		else
			swap (a, c);
	}  	
	return 0;
}
