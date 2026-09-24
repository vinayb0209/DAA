#include<iostream>
using namespace std;

int fib(int n){
    if(n<=1)
        return n;
    int prev2=0,prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n; // n is the index
    cout<<fib(n)<<endl;
	
		// output 5 for n=5
		// output 4 for n=3
    return 0;
}
