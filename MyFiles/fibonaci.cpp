#include <iostream>
#include <stdio.h>

using namespace std;

int Fibonacci(int x) { 
  if (x == 0) return 0;  // Stopping conditions 
  if (x == 1) return 1; 
  return Fibonacci(x - 1) + Fibonacci(x - 2); 
}

int main() { 
  int num;

  cin >> num; 
  cout << Fibonacci(num) << endl;

  return 0; 
} 
 
