#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> TwoSum(int a[],int n,int target){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        int compliment=target-a[i];
        if(map.find(compliment)!=map.end()){
            return {map[compliment],i};
        }
        map[a[i]]=i;
    }
    return {};
}
int main(){
    int n,a[100];
    cout << "Enter n: ";
    cin>>n;
    cout<<"Enter Elements:  ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter Target: ";
    int target; 
    cin>>target;
    cout<<"Pair is: ";
    vector<int> result=TwoSum(a,n,target);
    if(result.empty()){
        cout<<"None";
    }
    else{
        cout<<result[0]<<" "<<result[1];
    }
    // OUTPUT
// Enter n: 4
// Enter Elements:  2 7 11 15
// Enter Target: 13
// Pair is: 0 2
    return 0;
}
