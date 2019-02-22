#include "connect4.h"

//Connect4 Constructor
//Allocates board memory and intializes variables
Connect4::Connect4() {
	current_player = 1, column = 0, row = 0; //var init

	board = new int*[ROWS]; //allocate
	for (int i = 0; i < ROWS; i++) {
		board[i] = new int[COLS];
	}

	for (int row = 0; row < ROWS; row++) { //board init
		for (int column = 0; column < COLS; column++) {
			board[row][column] = 0;
		}
	}
}

//Connect4 Deconstructor
Connect4::~Connect4() {
	for (int i = 0; i < ROWS; i++)
		delete[] board[i];
	delete[] board;
}

//Asks the player for a column to place a piece in.
void Connect4::get_move() {
	column = 0, row = 0;
	cout << "Player " << current_player << "'s turn. ";
	cout << "Enter a column : " << endl;
	cin >> column;
}

//Clears the command line and prints out the board with pieces
void Connect4::print_board() {
	//clear screen
	system("cls");

	//header
	for (int column = 0; column < COLS; column++) {
		cout << " " << column;
	}
	cout << endl;

	//board
	for (int row = 0; row < ROWS; row++) {
		for (int column = 0; column < COLS; column++) {
			cout << "|" << board[row][column];
		}
		cout << "|" << endl;
	}
}

//Places piece in the lowest clear row in the column chosen
void Connect4::place_piece() {
	row = ROWS - 1; //starts at bottom of column instead of top
	while (row > 0 && board[row][column] != 0)
		row--;
	board[row][column] = current_player;
}

//Checks the top row for empty spaces
bool Connect4::game_over() {
	int count = 1;
	
	for (int i = 0; i < COLS; i++) //if top row multiplied together is zero, empty space is available
		count *= board[0][i];
	
	if (count == 0) //not game over if empty space detected
		return false;

	cout << "Tie game!" << endl;
	return true;
}

bool Connect4::check_win() {
	int current_player = board[row][column], count_horizontal = 1,
		count_vertical = 1, count_diagonal1 = 1, count_diagonal2 = 1;

	count_recursive(column, row, 1, 0,   count_horizontal);
	count_recursive(column, row, -1, 0,  count_horizontal);
	count_recursive(column, row, 0, 1,   count_vertical);
	count_recursive(column, row, 0, -1,  count_vertical);
	count_recursive(column, row, 1, -1,  count_diagonal1);
	count_recursive(column, row, -1, 1,  count_diagonal1);
	count_recursive(column, row, 1, 1,   count_diagonal2);
	count_recursive(column, row, -1, -1, count_diagonal2);

	if (count_horizontal == 5 || count_vertical == 5
		|| count_diagonal1 == 5 || count_diagonal2 == 5)
		cout << "Connect 5 detected!" << endl;

	if (count_horizontal >= 4) {
		cout << "Player " << current_player << " won horizontally!";
		return true;
	}
	if (count_vertical >= 4) {
		cout << "Player " << current_player << " won vertically!";
		return true;
	}
	if (count_diagonal1 >= 4) {
		cout << "Player " << current_player << " won diagonally!";
		return true;
	}
	if (count_diagonal2 >= 4) {
		cout << "Player " << current_player << " won diagonally!";
		return true;
	}

	return false;
}

//Iterates along the path set by direction x and direction y
//This solution by Daniel Ostermiller simplifies the problem immensely and allows for detection of connections larger than 4
//Since this solution was discussed in class, I believe it's part of the code we wrote in class, therefore not part of another student's lab
void Connect4::count_recursive(int column, int row, int dx, int dy, int &counter) {
	if (column + dx < 0 || //If the recursion tries to calculate past the left-most column
		row + dy < 0 || //If the recursion tries to calculate past the top row
		column + dx > COLS - 1 || //If the recursion tries to calculate past the right-most column
		row + dy > ROWS - 1) //If the recursion tries to calculate past the bottom row
		return; //returns for any out of bounds conditions listed above

	if (board[row + dy][column + dx] == current_player) { //detects if the next spot is part of the player's connection line
		counter++; //number of consecutive connections made if it is
		count_recursive(column + dx, row + dy, dx, dy, counter); //moves the "cursor" of this function to the next place (to the right, one spot) for checking
	}
}
