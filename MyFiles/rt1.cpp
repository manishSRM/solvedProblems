#include<iostream>

using namespace std;
 int main()
{  
   int i,j,n;
   cout<<"enter size\n";                                // &    
   cin>>n;                                              // & &   
   for(i=1;i<=n;++i)                                    // & & &
    { 
      for(j=n;j>=i;--j)
       {
         cout<<"*";
       }
     cout<<"\n";
   }
 return 0;
}
