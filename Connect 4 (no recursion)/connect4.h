//include stuff
#include <iostream>
using namespace std;

//constants
#define ROW 6
#define COL 7
#define WIN 4

void init_board(int b);
void printBoard(int b);
void p1_get_move(int &c);
void p2_get_move(int &c);
void update(int b, int c = -1, int p = 1); //if user send in an invalid move error, default player is 1
bool game_over(int b, int m = -1);
bool check_win(int **b, int m = -1);
