#include "bits/stdc++.h"

using namespace std;

const int N = 16;

bool isSafe(int ** board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;
    return true;
}

bool checkNQueen(int ** board, int row) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;
            if (checkNQueen(board, row + 1))
                return true;
            board[row][i] = 0;
        }
    }
    return false;
}

int main() {
    int ** board = new int * [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
        cout << endl;
    }

    cout << endl;

    if (!checkNQueen(board, 0))
        cout << "No solution.";
    
    return 0;
}