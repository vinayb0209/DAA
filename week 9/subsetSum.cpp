#include <iostream>
#include <vector>
using namespace std;
 
bool subsetSum(vector<int> &arr, int index, int remaining) {
    if (remaining == 0) return true;                       
    if (index == arr.size() || remaining < 0) return false; 
 
    
    if (subsetSum(arr, index + 1, remaining - arr[index])) return true;
 
    
    return subsetSum(arr, index + 1, remaining);
}
 
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
 
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    int target;
    cout << "Enter target sum: ";
    cin >> target;
 
    bool result = subsetSum(arr, 0, target);
 
    cout << (result ? "A subset with the given sum exists." : "No such subset exists.") << endl;
 
    return 0;
    
// Enter number of elements: 5
// Enter 5 elements: 3 34 4 12 52
// Enter target sum: 9
// A subset with the given sum exists.
}