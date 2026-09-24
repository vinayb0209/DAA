#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LIS(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"length of longest increasing subsequence is: ";
    cout<<LIS(arr);
    
    // Enter n: 8
    // Enter the elements: 10 9 2 5 3 7 101 18
    // length of longest increasing subsequence is: 4
    return 0;
}