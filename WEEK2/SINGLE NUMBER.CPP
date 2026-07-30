#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            result=result^nums[i];
        }
        return result;
    
    }
};
int main(){
    Solution s;
    vector<int> my_vec={1,3,5,7,9};
    cout<<s.singleNumber(my_vec)<<endl;
}
