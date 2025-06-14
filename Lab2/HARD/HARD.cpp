/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

HARD
- VALIDITY OF GIVEN TIC TAC TOE
*/

#include <iostream>
using namespace std;


int win[8][3] = {
    {0, 1, 2}, 
    {3, 4, 5}, 
    {6, 7, 8}, 
    {0, 3, 6}, 
    {1, 4, 7}, 
    {2, 5, 8}, 
    {0, 4, 8}, 
    {2, 4, 6}  
};


bool isWin(char *board, char c) {
    for (int i = 0; i < 8; i++) {
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c) {
            return true;
        }
    }
    return false;
}


bool isValid(char board[9]) {
    int xCount = 0, oCount = 0;

    // Count number of X's and O's
    for (int i = 0; i < 9; i++) {
        if (board[i] == 'X') xCount++;
        else if (board[i] == 'O') oCount++;
    }

    // Rule 1: X always goes first → xCount >= oCount
    if (oCount > xCount) return false;

    // Rule 2: Players alternate turns → xCount - oCount must be 0 or 1
    if (xCount - oCount > 1) return false;

    // Check wins
    bool xWin = isWin(board, 'X');
    bool oWin = isWin(board, 'O');

    // Rule 3: Both players can't win at the same time
    if (xWin && oWin) return false;

    // Rule 4: If X wins, xCount must be one more than oCount
    if (xWin && xCount != oCount + 1) return false;

    // Rule 5: If O wins, xCount must be equal to oCount
    if (oWin && xCount != oCount) return false;

    // All checks passed → valid board
    return true;
}

int main() {

    char board[9] = {
        'X', 'X', 'O',
        'O', 'O', 'X',
        'X', '.', '.'
    };

    if (isValid(board))
        cout << "Valid board" << endl;
    else
        cout << "Invalid board" << endl;

    return 0;
}
