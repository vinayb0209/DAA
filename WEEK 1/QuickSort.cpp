#include<iostream>
using namespace std;
void swap(int &a, int &b){
	int t=a;
	a=b;
	b=t;
}
int partition(int a[],int l,int h){
	int pivot=a[l];
	int i=l;
	int j=h;
	
	while(i<j){
		i++;
		while(pivot>=a[i] && i<h)
			i++;
		while(pivot<a[j] && j>=0)
			j--;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	swap(a[j],a[l]);
	return j;
}
void quicksort(int a[],int l, int h){
	if(l<h){
		int pi=partition(a,l,h);
	
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	
	}		
}
int main(){
	int a[100],n;
	cout<<"Enter n :";
	cin>>n;
	
	cout<<"Enter Elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	cout<<"Before:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";	

	quicksort(a,0,n-1);

	cout<<"After:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";	
	return 0;
}
