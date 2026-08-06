#include<stack>
#include<iostream>
using namespace std;
void NGE(int a[],int n){
	stack<int> s;
	int result[n];
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && s.top()<a[i])
			s.pop();
					
		if(s.empty())
			result[i]=-1;
		else 
			result[i]=s.top();
		s.push(a[i]);
	}
	cout<<"result:";
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	
	
}
int main(){
	
	int a[100],n;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	NGE(a,n);

	
	return 0;
}
