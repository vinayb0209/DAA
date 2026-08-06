//merge sort
#include<iostream>
using namespace std;
void merge(int a[],int l,int mid,int h){
	int n1=mid-l+1;
	int n2=h-mid;
	
	int left[n1],right[n2];
	
	
	
	for(int i=0;i<n1;i++)
		left[i]=a[i+l];
	for(int i=0;i<n2;i++)
		right[i]=a[i+mid+1];
		
	int k=l,i=0,j=0;
	while(i<n1&&j<n2){
		if(left[i]<=right[j])
			{
				a[k]=left[i];
				i++;
			}
		else 
			{
				a[k]=right[j];
				j++;
			}
		k++;
	}
	while(i<n1){
		a[k]=left[i];
		k++;
		i++;
	}
	while(j<n2){
		a[k]=right[j];
		j++;
		k++;
	}
		
}
void mergesort(int a[],int l, int h){
	if(l<h){
		int mid=(l+h)/2;
	
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		
		merge(a,l,mid,h);
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

	merge8sort(a,0,n-1);

	cout<<"After:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";	
	return 0;
}
