#include <iostream>
#include<vector>
using namespace std;

int matrixChainOrder(vector<int> &d,int n){
 
	vector<vector<int> > C(n,vector<int>(n,0));
 
	for(int len=2;len<n;len++){ // chain length
		for(int i=1;i<= n-len;i++){
			int j=i+len-1;
			C[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int cost=C[i][k]+C[k+1][j]+d[i-1]*d[k]*d[j];
				if(cost<C[i][j])
					C[i][j]=cost;
 			}
 		}		
 	}
 	return C[1][n-1];
}
int main() {
	int n;
	cout<<"Enter number of matrices:";
	cin>>n;
	
	vector<int> d(n+1);
	
	cout<<"Enter "<<(n + 1)<<" dimensions (d1,d2,d3....): ";
	for(int i=0; i<=n;i++){
		cin>>d[i];
	}
	int result=matrixChainOrder(d,n+1);
	cout<<"Minimum multiplications: "<<result<<endl;
 	return 0;
}



