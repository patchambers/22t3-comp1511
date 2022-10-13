// Function to check whether has won a game of tic tac toe
// Patrick Chambers (z5264081), 12/10/22

#include <stdio.h>

#define SIZE 5

int did_player_win(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Check whether the player has won the game
// Takes a char representing a player and the 2D array representing the board
// Returns 1 if this player has won, returns 0 otherwise
int did_player_win(char player, char board[SIZE][SIZE]) {

    // Check whether a player has gotten a full row
    
    // for loop to loop through row
    for (int i = 0; i < SIZE; i++) {
    // for loop to go through each column of each row
        int won = 1;
        for (int j = 0;j < SIZE; j++) {
            // If any char isn't this player's char, they haven't won yet
            if (board[i][j] != player) {
                won = 0;
            }
        }
        if (won == 1) {
            return 1;
        }

    }

    // Check whether a player has gotten a full column
    // Chosen to use a different strategy to rows, and also used row and col
    // in place of i and j
    int col = 0;
    while (col < SIZE) {
        int row = 0;
        int num_player_chars = 0;
        while (row < SIZE) {
            if (board[row][col] == player) {
                num_player_chars++;
            }
            row++;
        }
        // If the player has 5 chars in any column, they must have completed
        // the whole column and therefore won the game
        if (num_player_chars == SIZE) {
            return 1;
        }
        col++;
    }
    

    // TODO: Check whether a player has gotten one of the diagonals
    

    return 0;
}

