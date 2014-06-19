#include<iostream>

using namespace std;
int main()
{
	float s_intrst(float prnc, int time, float rate);

	 cout << "\nsimple intrset=" << s_intrst(6000,3,0.5) << "\n"; //call by value

	 return 0;
}
float s_intrst(float prnc,int time,float rate)
{
 	return((prnc*time*rate)/100);
}
