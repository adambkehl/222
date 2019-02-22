#include <pch.h>
#include <iostream>
#include "tictactoe.h"
using namespace std;

int main() {
	int board[3][3]; //board to hold moves
	int current_player = 1; //player whose turn it is
	init_board(board);
	int x = -1, y = -1;

	while (!game_over(board, x, y))	{
		
		get_move(&x, &y);
		update(board, x, y, current_player);

		if (current_player == 1)
			current_player = 2;
		else
			current_player = 1;
	}
}


void init_board(int board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0; // *(*(board + i) + j) = 0;
		}
	}
}

void update(int board[3][3], int x, int y, int player) {
	board[x][y] = player; // *(*(board + x) + y) = player;
}

bool game_over(int board[3][3], int x, int y) {
	if ((x == -1) || (y == -1)) return false;
	int score = 0;
	score = board[x][0] * board[x][1] * board[x][2];
	if (score == 1) {
		cout << "Player 1 wins" << endl;
		return true;
	}
	if (score == 8) {
		cout << "Player 2 wins" << endl;
		return true;
	}

	score = board[0][y] * board[1][y] * board[2][y];
	if (score == 1) {
		cout << "Player 1 wins" << endl;
		return true;
	}
	if (score == 8) {
		cout << "Player 2 wins" << endl;
		return true;
	}

	if ((x == 0 && y == 0) || (x == 2 && y == 2) || (x == 1 && y == 1))
		score = board[0][0] * board[1][1] * board[2][2];
	if (score == 1) {
		cout << "Player 1 wins" << endl;
		return true;
	}
	if (score == 8) {
		cout << "Player 2 wins" << endl;
		return true;
	}


	if ((x == 0 && y == 2) || (x == 2 && y == 0) || (x==1 && y ==1))
		score = board[0][2] * board[1][1] * board[2][0];
	if (score == 1) {
		cout << "Player 1 wins" << endl;
		return true;
	}
	if (score == 8) {
		cout << "Player 2 wins" << endl;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			score *= board[i][j];
		}
	}

	if (score != 0)
	{
		cout << "Tie" << endl;
		return true;
	}
	return false;
}

void get_move(int *a, int *b) {
	cout << "Enter row:";
	cin >> *a;
	cout << "Enter col:";
	cin >> *b;
}
