#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int LongConsSeq(vector<int> &arr,int n){
    unordered_set<int> numSet(arr.begin(), arr.end());
    
    int longest=0;
    for(int x : numSet){
        if(numSet.find(x-1)==numSet.end()){
        
            int length=1;
            while(numSet.find(x+length )!=numSet.end()){
                length++;
            }
            longest=max(longest,length);
        }
    }
    return longest;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Elements:  ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Longest consecutive sequence length: ";
    cout<<LongConsSeq(arr,n);
    // OUTPUT
    // Enter n: 6
    // Enter Elements:  100 4 200 1 3 2     
    // Longest consecutive sequence length: 4
    return 0;
}
