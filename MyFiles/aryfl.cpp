#include<iostream>

using namespace std;
 int main()
{ 
    int i,n,small,large;
    cout<<"Enter the number\n";
    cin>>n;

    int ary[n];
    cout<<"Enter the numbers of the array\n";
    for( i=0;i<n;++i)
     { 
      cin>>ary[i];
     }
      small=ary[0];
      large=ary[0];
   
   for(i=0;i<n;++i)
    {
      if(ary[i]>large)
      large=ary[i];
      else if(ary[i]<small)
      small=ary[i];
    } 
    cout<<"larger number is="<<large<<"\n";
    cout<<"smaller number is="<<small<<"\n";

return 0; 
}
