//Connect 4 main.cpp
//By Daniel Ostermiller
 
#include "Connect4.h"
 
int main(int args, char *argv[]) {
    int ply = 1;
    //create board
    int **board = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        board[i] = new int[COLS];
    }
 
    initBoard(board);
    printBoard(board);
 
    do {
        int x = 0;
        int y = 0;
        getMove(x, ply);
        placePiece(board, ply, x, y);
        printBoard(board);
 
        //if the lat move wins or ties the game is over
        if (checkWin(board, x, y) || gameOver(board)) {
            cout << endl << "Game Over!" << endl;
            break; //break out of the loop
        }
 
        //flop the player with ternary magic
        ply = ply == 1 ? 2 : 1;
    } while (true);
 
    //delete the board
    for (int i = 0; i < ROWS; i++) {
        delete[] board[i];
    }
    delete[] board;
 
    //Hacky bit that keeps the console open after game over on windows. If anyone has a better suggestion please let me know.
    getchar();
    getchar();
 
    return 0;
}
