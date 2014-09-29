#include <iostream>
#include <cstdio>

using namespace std;

void Fibonacci (int N) {
	int Fib[N];	
	Fib[1] = Fib[2] = 1;
	for (int i = 3; i <= N; i++)
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	cout << Fib[N] << endl;
}

int main() {
	int N; 
	cin >> N;
	Fibonacci(N);
	return 0;
}