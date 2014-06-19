#include<iostream>

using namespace std;

int main() {
	const int LENGTH = 21;
	char message[LENGTH];
	cout << "Enter a sentence on the line below." << endl;
	int i = 0;
	do
	{
		cin >> message[i];
		++i;
	}
	while (i < LENGTH - 1 && message[i] != '\n');	
	message[i] = '\0'; // Terminate string with NUL char.
	cout << message << endl;
	return 0;
}
