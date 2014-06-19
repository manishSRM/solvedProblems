#include<iostream>

using namespace std;

int main() { 
	char c;
    cout<<"Enter any charecter\n";       
    cin>>c;
    if(c >= 65 && c <= 90)
		c += 32;
    else 
    	if(c>=97&&c<=122)
    		c-=32;

      cout<<c;
      cout<<"\n";
return 0;
}
