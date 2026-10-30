#include <iostream>
#include <vector>   
using namespace std;
 
int n;
vector<vector<int>> maze;            
vector<vector<bool>> visited;
vector<string> allPaths;
 
void findPaths(int r, int c, string &path) {
    if (r == n - 1 && c == n - 1) {              
        allPaths.push_back(path);
        return;
    }
 
    visited[r][c] = true;                    
 
    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, -1, 1, 0};
    char move[4] = {'D', 'L', 'R', 'U'};
 
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
 
        bool inside = (nr >= 0 && nr < n && nc >= 0 && nc < n);
        if (inside && maze[nr][nc] == 1 && !visited[nr][nc]) {
            path.push_back(move[k]);            
            findPaths(nr, nc, path);
            path.pop_back();                   
        }
    }
 
    visited[r][c] = false;                     
}
 
int main() {
    cout << "Enter maze size N: ";
    cin >> n;
 
    maze.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
 
    cout << "Enter the maze (1 = open, 0 = blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
 
    string path = "";
    if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
        findPaths(0, 0, path);
    }
 
    if (allPaths.empty()) {
        cout << "No path exists." << endl;
    } else {
        cout << "Number of paths: " << allPaths.size() << endl;
        for (string &p : allPaths) cout << p << endl;
    }
 
    return 0;
    // output
    // Enter maze size N: 4
    // Enter the maze (1 = open, 0 = blocked):
    // 1 0 0 0
    // 1 1 0 1
    // 1 1 0 0
    // 0 1 1 1
    // Number of paths: 2
    // DDRDRR
    // DRDDRR

}