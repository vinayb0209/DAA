#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct Node {
    vector<vector<int>> mat;  
    vector<int> path;         
    int cost;                 
    int city;               
    int level;              
};
 
struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

int reduceMatrix(vector<vector<int>> &mat, int n) {
    int total = 0;
 
    for (int i = 0; i < n; i++) {                  
        int rowMin = INF;
        for (int j = 0; j < n; j++) rowMin = min(rowMin, mat[i][j]);
        if (rowMin != INF && rowMin > 0) {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != INF) mat[i][j] -= rowMin;
            total += rowMin;
        }
    }
 
    for (int j = 0; j < n; j++) {                
        int colMin = INF;
        for (int i = 0; i < n; i++) colMin = min(colMin, mat[i][j]);
        if (colMin != INF && colMin > 0) {
            for (int i = 0; i < n; i++)
                if (mat[i][j] != INF) mat[i][j] -= colMin;
            total += colMin;
        }
    }
    return total;
}
 
int tspBnB(vector<vector<int>> &cost, int n, vector<int> &bestPath,
           int &nodesCreated) {
    priority_queue<Node, vector<Node>, Compare> pq;
 
    Node root;
    root.mat = cost;
    root.path = {0};
    root.city = 0;
    root.level = 1;
    root.cost = reduceMatrix(root.mat, n);
    pq.push(root);
    nodesCreated = 1;
 
    while (!pq.empty()) {
        Node u = pq.top();                  
        pq.pop();
 
        if (u.level == n) {               
            bestPath = u.path;
            return u.cost;                 
        }
 
        for (int next = 0; next < n; next++) {
            if (u.mat[u.city][next] == INF) continue;  
 
            Node child;
            child.mat = u.mat;
            child.path = u.path;
            child.path.push_back(next);
            child.city = next;
            child.level = u.level + 1;
 
            

            for (int k = 0; k < n; k++) {
                child.mat[u.city][k] = INF;
                child.mat[k][next] = INF;
            }
            child.mat[next][0] = INF;

            child.cost = u.cost + u.mat[u.city][next]
                         + reduceMatrix(child.mat, n);
 
            pq.push(child);
            nodesCreated++;
        }
    }
    return -1;
}
 
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
 
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n
         << " cost matrix (diagonal is ignored):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (i == j) cost[i][j] = INF;   
        }
    }
 
    vector<int> bestPath;
    int nodesCreated = 0;
    int best = tspBnB(cost, n, bestPath, nodesCreated);
 
    cout << "Minimum tour cost: " << best << endl;
    cout << "Tour: ";
    for (int city : bestPath) cout << city << " -> ";
    cout << bestPath[0] << endl;
    cout << "State space nodes created: " << nodesCreated << endl;
 
    return 0;

    //OUTPUT
    // Enter number of cities: 5
    // Enter the 5x5 cost matrix (diagonal is ignored):
    //   0  20  30  10  11
    //  15   0  16   4   2
    //   3   5   0   2   4
    //  19   6  18   0   3
    //  16   4   7  16   0
    // Minimum tour cost: 28
    // Tour: 0 -> 3 -> 1 -> 4 -> 2 -> 0
    // State space nodes created: 11
}