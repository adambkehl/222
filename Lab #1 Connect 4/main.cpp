#include "connect4.h"

int main(int argc, char **argv) {
	Connect4 c;

	while (!c.game_over()) {
		c.get_move();
		c.place_piece();
		c.print_board();
		if (c.check_win() || c.game_over()){
			cout << endl << "Game over!" << endl;
			break;
		}
		c.current_player = c.current_player == 1 ? 2 : 1;
	}
	cin.get(), cin.get();
	return 0;
}
