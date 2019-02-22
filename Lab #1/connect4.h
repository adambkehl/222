#include <iostream>
using namespace std;

#define ROWS 6
#define COLS 7

class Connect4 {
public:
	Connect4();
	~Connect4();
	bool game_over();
	void get_move();
	void place_piece();
	void print_board();
	bool check_win();
	void count_recursive(int x, int y, int dx, int dy, int &counter);
	int current_player, **board, column, row;

};
