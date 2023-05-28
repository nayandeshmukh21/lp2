#include <iostream>
#include <vector>
//int n;

using namespace std;

// A utility function to print the solution
void printSolution(const vector<vector <int> >& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

// A utility function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<vector <int> >& board, int row, int col) {
    int n = board.size();

    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }

    // Check the upper diagonal on the left side
	//This loop checks the upper diagonal on the left side. It iterates from the 
	//current row and col position towards the top-left corner of the board. 
	//If a queen is found in any of the cells on the upper diagonal, the function returns false, 
	//indicating that the current position is not safe.
	
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// A recursive utility function to solve the N Queen problem
bool solveNQUtil(vector<vector <int> >& board, int col) {
    int n = board.size();

    // Base case: If all queens are placed, return true
    if (col >= n)
        return true;

    // Consider this column and try placing the queen in all rows one by one
    for (int i = 0; i < n; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing the queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col] (backtracking)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column col, return false
    return false;
}

// This function solves the N Queen problem using backtracking.
// It mainly uses solveNQUtil() to solve the problem.
// It returns false if queens cannot be placed, otherwise, returns true
// and prints the placement of queens in the form of 1s.
bool solveNQ(int n) {
    vector<vector <int> > board(n, vector <int> (n, 0));

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board);
    return true;
}

// Driver program to test the above function
int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    solveNQ(n);

    return 0;
}

