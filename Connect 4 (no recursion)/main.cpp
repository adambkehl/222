#include <iostream>
#include "connect.h"

using namespace std;

int main(int argc, char argv)
{
    int board; //also can do int *board = new int[ROW][COL]
    int column = -1, c_player = 1;

    board = new int[ROW]; //memory allocation for 2d arrays is actually 3 stacks, it stores both the memory locations of the ints and the ints

    for (int i = 0; i < ROW; i++)
        board[i] = new int[COL];

    init_board(board);

    while(!game_over(board, column)) //game_over has a default parameter, don't worry bout it for the first time through
    {
        if (c_player == 1)
            p1_get_move(column);
        else
            p2_get_move(column);

        update(board, column, c_player);
        printBoard(board);
        if (c_player == 1)
            c_player = 2;
        else
            c_player = 1; 
    }

    //DESTRUCTION
    for (int i = 0; i < COL; i++)
        delete[]board[i]; //bracket tells it to go through and delete everything
    delete[]board;

    return 0;
}
