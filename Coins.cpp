#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int coinChange(vector<int> &coins,int amount) {
 	vector<int> dp(amount + 1,INT_MAX);
 	dp[0] = 0;
 	for(int i=1; i<=amount;i++) {
 			for (int c : coins) {
 					if(c<=i && dp[i - c]!=INT_MAX){
 						dp[i]=min(dp[i],dp[i-c]+1);
					}
 			}
 	}
 	return (dp[amount]==INT_MAX) ? -1 : dp[amount];
}

int main() {
 int n;
 cout << "Enter number of coin denominations: ";
 cin >> n;
 
 vector<int> coins(n);
 
 cout<<"Enter "<<n<<" coin denominations:";
 for(int i=0; i<n;i++){
 	cin>>coins[i];
 }
 
 int amount;
 cout<<"Enter target amount: ";
 cin>>amount;
 
 int result=coinChange(coins, amount);
 if(result == -1)
 	cout<<"It is not possible to make this amount."<<endl;
 else
 	cout << "Minimum coins needed: " << result << endl;
 	
// Enter number of coin denominations: 3
// Enter 3 coin denominations:1 2 5
// Enter target amount: 11
// Minimum coins needed: 3
 	
 return 0;
}

