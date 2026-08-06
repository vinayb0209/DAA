//Inversion Count
#include<iostream>
using namespace std;
int inversionCount(int a[],int n){
		int count=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				count ++;
	}
	return count;
}

int main(){
	int a[100],n;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"Count:"<<inversionCount(a,n)<<endl;	
	
	return 0;
}
