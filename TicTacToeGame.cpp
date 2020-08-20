// Ashley Stojak
// Tic-Tac-Toe Game

#include <iostream>
#include <stdlib.h>
using namespace std;

// Purpose of function is to create the tic tac toe game board
void displayBoard(char board[][3]) {
    cout << endl;
	cout << "       |     |     " << endl;
    cout << "    " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " " << endl;
    cout << "  _____|_____|_____" << endl;
    cout << "       |     |     " << endl;
    cout << "    " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " " << endl;
    cout << "  _____|_____|_____" << endl;
    cout << "       |     |     " << endl;
    cout << "    " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " " << endl;
    cout << "       |     |     " << endl;
    cout << endl;
}

// Purpose of function is to display the player's game piece on the board in accordance to the spot they inputted and to check if that spot if valid 
bool playersMove(char board[][3], char &player, int playersInput) {

    int row = 0;
    int column = 0;

    // check to see if input is valid and get position of the spot the user picked
    switch(playersInput) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid move. Please enter a number 1-9." << endl;
            return false;
    }

    // check to see if the spot the player chose is already filled
    if (board[row][column] == 'X' || board[row][column] == 'O') {
        cout << "This spot is already filled! Please choose a different spot." << endl;
        return false;
    }

    // assign player's game piece to the spot they picked on the board
    if (player == 'X') {
        board[row][column] = 'X';
        player = 'O';
    } else {
        board[row][column] = 'O';
        player = 'X';
    }

    displayBoard(board);

    return true; // return true, move is valid
}

// Purpose of function is to check whether a player has won or if the players tied
bool gameOver(char board[][3], bool &tie) {

    // check columns and rows for three in a row
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return true;
        }
    }

    // check diagonals for win
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
        return true;
    }

    // loop through board to see if all the spots are filled to see if there is a tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if((board[i][j] != 'X') && (board[i][j] != 'O')) {
                return false;
            }
        }
    }

    tie = true; // if board is full, there is a tie

    return true;
}


int main() {

    char player = 'X';
    int playersInput = 0;
    bool tie = false;

    // array to represent the spots on the board
	char board[3][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'}};

    // explain directions of game to user
    cout << "Welcome to Tic Tac Toe!" << endl << endl;
    cout << "This is a two player game. To make a move, input" << endl;
    cout << "the number on the board where you want your game" << endl; 
    cout << "piece to go. First person to fill three spots in a row" << endl;
    cout << "with their game pieces wins the game!" << endl << endl;

    cout << "Player 1 is X's and Player 2 is O's." << endl;

    // display the board
	displayBoard(board);

    while(!gameOver(board, tie)) { // while game is not over

        if (player == 'X') { // player 1's turn
            cout << "Player 1 (X) turn: ";
        }
        else { // player 2's turn
            cout << "Player 2 (O) turn: ";
        }

        cin >> playersInput; // get user's input

        if (!playersMove(board, player, playersInput)) { // if playersMove() returns false, move is invalid so ask for user input again
            continue;
        }

    }

    // display end of game message that says who the winner is
    if (tie == true) { // tie, no winner
        cout << "Tie! No winners :(" << endl;
    }
    else if (player == 'O') { // if its on player O, then X wins since X made the last move but was changed to O in playersMove()
        cout << "Congratulations Player 1 (X)! You won!" << endl;
    }
    else {
        cout << "Congratulations Player 2 (O)! You won!" << endl;
    }

	return 0;
}