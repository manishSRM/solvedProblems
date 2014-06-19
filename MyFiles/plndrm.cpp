#include<iostream>

using namespace std;
int main()
 {
   int n,num,rnum=0,r;
   cout<<"Enter the number\n";
   cin>>num; 
   n=num; 
   while(num)
   {
     r = num % 10;
     rnum = rnum * 10 + r;
     num /= 10;
    }
   if(n == rnum)
    cout << "Entered number is palindrome number\n";
  else
    cout << "Entered number is not a palindrome number\n";
   return 0;
 }
