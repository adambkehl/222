//Connect 4 connect4.h
//By Daniel Ostermiller

#pragma once

#include <iostream>
using namespace std;
#define ROWS 6
#define COLS 7
#define WIN 4

void initBoard(int **board);

void getMove(int &x, int ply);
void printBoard(int **board);
void placePiece(int **board, int ply, int &x, int &y);

bool gameOver(int **board);
bool checkWin(int **board, int r, int c);

void countRecursive(int **board, int ply, int x, int y, int dx, int dy, int &counter);
