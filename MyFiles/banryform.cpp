#include<iostream>

using namespace std;

int binaryForm (int num) {
	return (num % 2);
}

int main()
{
	int num, r, i;
	cin >> num;
	cout << "Binary form = ";
	for (i = num; i != 0; i /= 2) {
		r = binaryForm (i);
		cout << r; 
	}
	cout << "\n";
	return 0;
}
