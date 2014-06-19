
#include<iostream>

using namespace std;
int main()
 { 
    int num,sum=0;
    cout<<"Enter thew number\n";
    cin>>num;

     while(num)
      {
        sum+=num%10;
        num/=10;
      }
     cout<<"sum of the digits="<<sum<<"\n";
     return 0;
  }
