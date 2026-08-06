#include<iostream>
using namespace std;
int Sum(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
}
 int main(){
 	int a[100],n;
 	cout<<"enter n:";
 	cin>>n;
 	cout<<"enter elements :";
 	for(int i=0;i<n;i++)
 		cin>>a[i];
 		
 	cout<<"sum:"<<Sum(a,n)<<endl;
 	cout<<"Avg:"<<(float)Sum(a,n)/n<<endl;
 	
 	return 0;
 }
