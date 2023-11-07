#include <iostream>
using namespace std;

bool isSafe(int board[8][8], int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[8][8], int col) {
    if (col >= 8) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int board[8][8] = {0}; // Initialize an 8x8 chessboard
    int firstQueenRow, firstQueenCol;

    cout << "Enter the position (row and column) of the first Queen (0-7): ";
    cin >> firstQueenRow >> firstQueenCol;

    if (firstQueenRow < 0 || firstQueenRow >= 8 || firstQueenCol < 0 || firstQueenCol >= 8) {
        cout << "Invalid position for the first Queen." << endl;
        return 1;
    }

    board[firstQueenRow][firstQueenCol] = 1;

    if (solveNQueens(board, 0)) {
        cout << "Solution found!" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found with the specified initial position of the first Queen." << endl;
    }

    return 0;
}

