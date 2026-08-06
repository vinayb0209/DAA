#include<iostream>
using namespace std;
bool powof2(int n)
{
	return !((n & (n-1)));
}
int main(){
	
	int n;
	cout<<"Enter number:";
	cin>>n;
	
	if(powof2(n)){
		cout<<"yes";
	}else 
		cout<<"no";
	return 0;
}
