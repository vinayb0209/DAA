#include<iostream>
using namespace std;

int ways(int n){
    if(n<=2)
        return n;
    int prev2=1,prev1=2;
    for(int i=3;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;

    cout<<ways(n)<<endl;
	// n=5 output 8
	// n=4 output 5
	// n=3 output 3
    return 0;
}
