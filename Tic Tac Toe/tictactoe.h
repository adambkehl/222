#pragma once
void init_board(int board[][3]); //or [3][3]
void get_move(int *x, int *y);
void update(int board[3][3], int, int, int);
bool game_over(int board[3][3], int, int);
