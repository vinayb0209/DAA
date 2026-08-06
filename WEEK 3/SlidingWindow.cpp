
#include<vector>
#include<deque>
#include<iostream>
using namespace std;
void SW(int a[],int n,int k){
	vector<int> result;
	deque<int> dq;
	for(int i=0;i<k;i++){
		while(!dq.empty() && a[dq.back()]<a[i])
			dq.pop_front();
		dq.push_back(i);
	}
	result.push_back(a[dq.front()]);
	for(int i=k;i<n;i++){
		//for k size 
		if(dq.front()<i-k+1)
			dq.pop_front();
		while(!dq.empty() && a[i]>a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
		result.push_back(a[dq.front()]);
	}

	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
}
int main(){
	cout<<"Enter n";
	int a[100],n;
	cin>>n;
	cout<<"Enter elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Size of window(k):";
	int k;
	cin>>k;
	SW(a,n,k);	
	return 0;
}
