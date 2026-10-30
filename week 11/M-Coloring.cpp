#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
bool isSafe(int v, int c, vector<vector<int>> &graph, vector<int> &colors) {
    for (int u = 0; u < v; u++) {
        if (graph[v][u] == 1 && colors[u] == c) return false;
    }
    return true;
}
 
bool mColoringBnB(vector<vector<int>> &graph, int n, int m,
                  vector<int> &answer, int &nodesCreated) {
    queue<vector<int>> live;    
    live.push({});               
    nodesCreated = 1;
 
    while (!live.empty()) {
        vector<int> state = live.front();   
        live.pop();
 
        int v = state.size();               
        if (v == n) {                      
            answer = state;
            return true;
        }
 
        for (int c = 1; c <= m; c++) {   
            if (isSafe(v, c, graph, state)) {  
                vector<int> child = state;
                child.push_back(c);
                live.push(child);
                nodesCreated++;
            }
        }
    }
    return false;                         
}
 
int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
 
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
 
    cout << "Enter number of colours m: ";
    cin >> m;
 
    vector<int> answer;
    int nodesCreated = 0;
 
    if (mColoringBnB(graph, n, m, answer, nodesCreated)) {
        cout << "Colouring possible with " << m << " colours:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Colour " << answer[i] << endl;
    } else {
        cout << "Not possible with " << m << " colours." << endl;
    }
    cout << "State space nodes created: " << nodesCreated << endl;
 
    return 0;

    // OUTPUT
// Enter number of vertices: 4
// Enter the 4x4 adjacency matrix:
// 0 1 1 0
// 1 0 1 0
// 1 1 0 1
// 0 0 1 0
// Enter number of colours m: 3
// Colouring possible with 3 colours:
// Vertex 0 -> Colour 1
// Vertex 1 -> Colour 2
// Vertex 2 -> Colour 3
// Vertex 3 -> Colour 1
// State space nodes created: 28
}