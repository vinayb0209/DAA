#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>    
using namespace std;

struct State {
    int r, c;               
    vector<int> path;       
};
 
bool enoughLetters(vector<vector<char>> &board, int rows, int cols,
                   string &word) {
    map<char, int> have, need;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            have[board[r][c]]++;
    for (char ch : word) need[ch]++;
 
    for (auto &p : need) {
        if (have[p.first] < p.second) return false;
    }
    return true;
}
 
bool wordSearchBnB(vector<vector<char>> &board, int rows, int cols,
                   string &word, int &nodesCreated) {
    nodesCreated = 0;
    if (!enoughLetters(board, rows, cols, word)) return false;  
 
    queue<State> live;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == word[0]) {
                State s;
                s.r = r;
                s.c = c;
                s.path.push_back(r * cols + c);
                live.push(s);
                nodesCreated++;
            }
        }
    }
 
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
 
    while (!live.empty()) {
        State s = live.front();           
        live.pop();
 
        int matched = s.path.size();      
        if (matched == (int)word.size()) return true;
 
        for (int k = 0; k < 4; k++) {      
            int nr = s.r + dr[k];
            int nc = s.c + dc[k];
 
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (board[nr][nc] != word[matched]) continue;   
 
            int id = nr * cols + nc;
            if (find(s.path.begin(), s.path.end(), id) != s.path.end())
                continue;                                 
 
            State child = s;               
            child.r = nr;
            child.c = nc;
            child.path.push_back(id);
            live.push(child);
            nodesCreated++;
        }
    }
    return false;
}
 
int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
 
    vector<vector<char>> board(rows, vector<char>(cols));
    cout << "Enter the board row by row (no spaces):\n";
    for (int r = 0; r < rows; r++) {
        string rowStr;
        cin >> rowStr;
        for (int c = 0; c < cols; c++) board[r][c] = rowStr[c];
    }
 
    string word;
    cout << "Enter the word to search: ";
    cin >> word;
 
    int nodesCreated = 0;
    bool found = wordSearchBnB(board, rows, cols, word, nodesCreated);
 
    cout << (found ? "Word exists on the board." :
                     "Word does not exist on the board.") << endl;
    cout << "State space nodes created: " << nodesCreated << endl;
 
    return 0;
    //OUTPUT
    // Enter number of rows and columns: 3 4
    // Enter the board row by row (no spaces):
    // ABCE
    // SFCS
    // ADEE
    // Enter the word to search: ABCCED
    // Word exists on the board.
    // State space nodes created: 7
}