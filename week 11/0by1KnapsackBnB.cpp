#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
struct Item {
    int weight;
    int value;
};
 
struct Node {
    int level;      
    int profit;      
    int weight;     
    double bound;   
};
 

struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.bound < b.bound;
    }
};

bool byRatio(const Item &a, const Item &b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}
 
double bound(const Node &u, int n, int W, vector<Item> &items) {
    double result = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;
 
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        result += items[j].value;
        j++;
    }
    if (j < n) {
        result += (W - totalWeight) * (double)items[j].value / items[j].weight;
    }
    return result;
}
 
int knapsackBnB(vector<Item> &items, int n, int W) {
    sort(items.begin(), items.end(), byRatio);
 
    priority_queue<Node, vector<Node>, Compare> pq;
 
    Node root = {-1, 0, 0, 0};
    root.bound = bound(root, n, W, items);
    pq.push(root);
 
    int maxProfit = 0;                     
 
    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
 
        if (u.bound <= maxProfit) 
            continue; 
        if (u.level == n - 1) 
            continue;    
 
        int next = u.level + 1;
 
        Node take = {next, u.profit + items[next].value,
                     u.weight + items[next].weight, 0};
        if (take.weight <= W) {            
            if (take.profit > maxProfit) maxProfit = take.profit;
            take.bound = bound(take, n, W, items);
            if (take.bound > maxProfit) pq.push(take);
        }
 
        Node skip = {next, u.profit, u.weight, 0};
        skip.bound = bound(skip, n, W, items);
        if (skip.bound > maxProfit) pq.push(skip);
    }
    return maxProfit;
}
 
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
 
    vector<Item> items(n);
    cout << "Enter " << n << " weights: ";
    for (int i = 0; i < n; i++) cin >> items[i].weight;
 
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) cin >> items[i].value;
 
    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;
 
    cout << "Maximum value: " << knapsackBnB(items, n, W) << endl;
 
    return 0;
    // OUTPUT
    // Enter number of items: 4
    // Enter 4 weights: 2 1 3 2
    // Enter 4 values: 12 10 20 15
    // Enter knapsack capacity: 5
    // Maximum value: 37

    // OUTPUT 2
    // Enter number of items: 4
    // Enter 4 weights: 1 3 4 5 
    // Enter 4 values: 1 4 5 7 
    // Enter knapsack capacity: 7
    // Maximum value: 9
}