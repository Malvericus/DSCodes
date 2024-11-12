#include <iostream>
using namespace std;

void display(vector<vector<bool>> board) {
    for (auto row : board) {
        for (bool cell : row) {
            if (cell)
            {
                cout << "Q ";
            }
            else {
                cout << "x ";
            }
            
        }
        cout << endl;
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<vector<bool>> board, int row, int col) {
    // Check vertical column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check left diagonal
    for (int i = 1; i <= min(row, col); i++) {
        if (board[row - i][col - i]) return false;
    }

    // Check right diagonal
    for (int i = 1; i <= min(row, (int)board.size() - col - 1); i++) {
        if (board[row - i][col + i]) return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
int solveNQueens(vector<vector<bool>> board, int row) {
    if (row == board.size()) {
        display(board);
        cout << endl;
        return 1; // Found a solution
    }

    int count = 0;

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            count += solveNQueens(board, row + 1); // Recurse for the next row
            board[row][col] = false; // Backtrack
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter size of chessboard: ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));

    cout << "Number of solutions: " << endl;
    cout << solveNQueens(board, 0) << endl;

    return 0;
}