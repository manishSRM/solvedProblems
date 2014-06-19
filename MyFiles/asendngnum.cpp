#include<iostream>

using namespace std;

int main()
{
	int a, b, c, large, small, middle;
	cin >> a >> b >> c;
	if (a > b && a > c) {
		large = a;
		if (b > c) {
			middle = b;
			small = c;
			}
		else    {
			middle = c;
			small = b;
			}
	 }
	 else if (b > a && b > c) {
		large = b;
		if (a > c) {
			middle = a;
			small = c;
			}
		else    {
			middle = c;
			small = a;
			}
	 }
	else {
		large = c;
		if (a > b) {
			middle = a;
			small = b;
			}
		else    {
			middle = b;
			small = a;
			}
	 }
	cout << "Increasig order = ";
	cout << small << " " << middle << " " << large << "\n";
	return 0;
}
