#include <iostream>
#include <vector>   
using namespace std;

int knapsack(vector<int> &weights,vector<int> &values,int n,int W){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(weights[i-1]>j){
            dp[i][j]=dp[i-1][j]; 
            }else{
            dp[i][j]=max(dp[i - 1][j],values[i-1]+dp[i-1][j-weights[i-1]]); 
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n;
    cout<<"Enter number of items:";
    cin>>n;
    vector<int> weights(n),values(n);
 cout << "Enter weights: ";
 for (int i = 0; i < n; i++) 
    cin >> weights[i];
 cout << "Enter values: ";
 for (int i = 0; i < n; i++) 
    cin >> values[i];
 int W;
 cout << "Enter knapsack capacity: ";
 cin >> W;
 cout << "Maximum value:" <<knapsack(weights, values, n, W) << endl;


//  Enter number of items:4
// Enter weights: 1 3 4 5
// Enter values: 1 4 5 7
// Enter knapsack capacity: 7
// Maximum value:9
    return 0;
}
