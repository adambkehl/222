//Connect 4 connect4.cpp
//By Daniel Ostermiller
 
#include "Connect4.h"
 
//clears the board memory to all 0
void initBoard(int **board)
{
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            board[y][x] = 0;
        }
    }
}
 
//asks the player for a column to place a piece in.
void getMove(int & x, int ply)
{
    cout << "Enter Move p" << ply << endl;
    cin >> x;
    //Don't let the player be an idiot and crash the game... clamp x in bounds!
    //(this is the same as if clamping with if-else if-else.)
    x = (x < 0) ? 0 : (x > COLS - 1) ? COLS - 1 : x;
}
 
//clears the screen and prints out the game board with a nice header.
void printBoard(int **board)
{
    //Clear the console before printing new board. (may cause issues on some machines)
    system("CLS");
 
    //print out the header.
    cout << "Connect " << WIN << " in a row to win!" << endl << endl;
 
    //loops over the whole board and displays
    for (int y = -1; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            //the -1 in the y loop is for printing header
            if (y == -1) {
                cout << "|" << x << "|";
                continue; // we want to continue to the next iteration of our loop skipping code below.
            }
 
            //print out the board characters with ternary magic
            int v = board[y][x];
            cout << (v==1 ? "|X|" : v==2 ? "|O|" : "|_|");
        }
        cout << endl;
    }
}
 
void placePiece(int **board, int ply, int &x, int &y)
{
    y = ROWS-1;
    //start at the bottom and slide the move up as long as the place isn't free
    //this simulates the gravity of the piece (except starting from the bottom up cause it's faster on average)
    while (y>0 && board[y][x] != 0) {
        y--;
    }
    //assign the moved to cell its player
    board[y][x] = ply;
}
 
bool gameOver(int **board)
{
    //multiply all of the top rows columns together if any are 0 we know theres a place free
    int count = 1;
    for (int i = 0; i < COLS; i++) {
        count *= board[0][i];
    }
 
    //if count is not 0 the top rows been filled and the game is over
    if (count != 0) {
        cout << "It's a tie!" << endl;
        return true;
    }
    return false;
}
 
bool checkWin(int **board, int x, int y)
{
    int ply = board[y][x]; //gets the current player from our move
 
    //the below code resets the counter to 1 because we know for certain there
    //will always be at least 1 match at this location.. it's our current move.
 
    //horizontal win check
    int count = 1;
    countRecursive(board, ply, x, y, 1, 0, count);
    countRecursive(board, ply, x, y, -1, 0, count);
    if (count >= 4) {
        cout << "P" << ply << " Wins horizontally!";
        return true;
    }
    //vertical win check
    count = 1;
    countRecursive(board, ply, x, y, 0, 1, count);
    countRecursive(board, ply, x, y, 0, -1, count);
    if (count >= 4) {
        cout << "P" << ply << " Wins vertically!";
        return true;
    }
 
    //diagonal forward win check
    count = 1;
    countRecursive(board, ply, x, y, 1, -1, count);
    countRecursive(board, ply, x, y, -1, 1, count);
    if (count >= 4) {
        cout << "P" << ply << " Wins diagonally!";
        return true;
    }
 
    //diagonal back win check
    count = 1;
    countRecursive(board, ply, x, y, 1, 1, count);
    countRecursive(board, ply, x, y, -1, -1, count);
    if (count >= 4) {
        cout << "P" << ply << " Wins diagonally!";
        return true;
    }
 
    return false;
}
 
 
//This method will continue to call itself as long as there is a match in
//the direction given by dx and dy
//int &counter is our pass-by-reference variable that gets incremented when
//we have a matching neighbor.
void countRecursive(int **board, int ply, int x, int y, int dx, int dy, int &counter) {
    //if the location is out of bounds return!
    if (x+dx<0 || y+dy<0 || x+dx>COLS-1 || y+dy>ROWS-1)
        return;
 
    //else check if we have a matching neighbor
    if (board[y+dy][x+dx] == ply) {
        counter++;
        //continue as long as we have a match in this direction
        countRecursive(board, ply, x+dx, y+dy, dx, dy, counter);
    }
}
