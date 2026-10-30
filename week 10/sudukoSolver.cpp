#include <iostream>
#include <vector>
using namespace std;
 
bool isSafe(vector<vector<char>> &board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;    
        if (board[i][col] == num) return false;  
    }
 
    int startRow = (row / 3) * 3;                  
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}
 
bool solveSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {         
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;   
                        if (solveSudoku(board)) return true;
                        board[row][col] = '.';      
                    }
                }
                return false;                      
            }
        }
    }
    return true;                                   
}
 
int main() {
    vector<vector<char>> board(9, vector<char>(9));
 
    cout << "Enter the board: 9 rows of 9 characters, use '.' for empty:\n";
    for (int i = 0; i < 9; i++) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < 9; j++) board[i][j] = rowStr[j];
    }
 
    if (solveSudoku(board)) {
        cout << "\nSolved board:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
    // OUTPUT
    // Enter the board: 9 rows of 9 characters, use '.' for empty:
    // 5 3 . . 7 . . . .
    // 6 . . 1 9 5 . . .
    // . 9 8 . . . . 6 .
    // 8 . . . 6 . . . 3
    // 4 . . 8 . 3 . . 1
    // 7 . . . 2 . . . 6
    // . 6 . . . . 2 8 .
    // . . . 4 1 9 . . 5
    // . . . . 8 . . 7 9
    // Solved board:
    // 5 3 4 6 7 8 9 1 2
    // 6 7 2 1 9 5 3 4 8
    // 1 9 8 3 4 2 5 6 7
    // 8 5 9 7 6 1 4 2 3
    // 4 2 6 8 5 3 7 9 1
    // 7 1 3 9 2 4 8 5 6
    // 9 6 1 5 3 7 2 8 4
    // 2 8 7 4 1 9 6 3 5
    // 3 4 5 2 8 6 1 7 9 
    return 0;
}