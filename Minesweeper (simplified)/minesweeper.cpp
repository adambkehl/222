//------- minesweeper.cpp -------
//#include "minesweeper.h"
 
minesweeper::minesweeper() {
    get_settings(); //gets size of board and difficulty
 
    //Allocates 2D array
    board = new cell*[row];
    for (int i = 0; i < row; i++) {
        board[i] = new cell[col];
    }
 
    //Places bombs
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (rand() % (row*col) + 1 < (probability / 100.00) * (row*col)) {
                board[i][j].set_bomb(true);
            }
        }
    }
}
 
minesweeper::~minesweeper() {
//Deallocates our 2D array
    for (int i = 0; i < row; i++) {
        delete[] board[i];
    }
    delete[] board;
}
 
//Gets user settings such as size and difficulty
void minesweeper::get_settings() {
    int row_size, column_size, difficulty;
 
    cout << "Enter row size: ";
    cin >> row_size;
    cout << "Enter column size: ";
    cin >> column_size;
    cout << "Enter difficulty (1 - easy, 2 - med, 3 - hard): ";
    cin >> difficulty;
 
    row = row_size;
    col = column_size;
 
    if (difficulty == 1) probability = EASY;
    else if (difficulty == 2) probability = MED;
    else if (difficulty == 3) probability = HARD;
    else cout << "Invalid difficulty setting.";
}
 
//Calculates number of bombs next to each cell
//Assigns that number to the bombs_near variable
void minesweeper::count_bombs_near() {
    int count;
    bool open_top, open_bottom, open_left, open_right;
 
    //Cycles through all positions on the board (including oob)
    //
    //Shorter way would be:
    //for (int r = 1; r < row - 1; r++) {
    //  for (int c = 1; c < col - 1; c++) {
    //and then you wouldn't need the booleans
    //
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
 
            count = 0;
            open_top = false, open_bottom = false, open_left = false, open_right = false;
 
            //Determines if the cell is within bounds
            //Longer way of doing:  if (x < 0 || y < 0 || x >= row || y >= col)
            if (r > 0) open_top = true;
            if (c > 0) open_left = true;
            if (c < col - 1) open_right = true;
            if (r < row - 1) open_bottom = true;
 
            //Checks for a bomb above, above and to the right, and above and to the left
            if (open_top){
                if (board[r - 1][c].get_bomb()) count++;
                if (open_right)
                    if (board[r - 1][c + 1].get_bomb()) count++;
                if (open_left)
                    if (board[r - 1][c - 1].get_bomb()) count++;
            }
 
            //Checks for a bomb below, below and to the right, and below and to the left
            if (open_bottom) {
                if (board[r + 1][c].get_bomb()) count++;
                if (open_right)
                    if (board[r + 1][c + 1].get_bomb()) count++;
                if (open_left)
                    if (board[r + 1][c - 1].get_bomb()) count++;
            }
 
            //Checks for a bomb to the left and right
            if (open_right)
                if (board[r][c + 1].get_bomb()) count++;
            if (open_left)
                if (board[r][c - 1].get_bomb()) count++;
 
 
            //Finally, assigns the surrounding bomb count to the cell
            board[r][c].set_bombs_near(count);
 
        }
    }
}
 
//Gets where the user selected, either to mark or expose
void minesweeper::get_user_move() {
    int selection, selection_row, selection_col;
 
    cout << endl << "(1) mark bomb" << endl << "(2) open cell" << endl;
    cin >> selection;
 
    cout << "Enter row, then column: " << endl;
    cin >> selection_row;
    cin >> selection_col;
 
    if (selection == 1) {
        //makes the flag opposite what it was previously
        //i.e. if the cell is already flagged, it's not flagged anymore
        board[selection_row][selection_col].set_flagged(!board[selection_row][selection_col].get_flagged());
    }
    else if (selection == 2) {
        if (board[selection_row][selection_col].get_bomb()) {
            //Losing condition. Marks as exposed, returns to main, main calls game_over, and
            //game is now over because bomb is exposed
            board[selection_row][selection_col].set_exposed(true);
            return;
        } else {
            reveal_at(selection_row, selection_col);
        }
    } else {
        cout << "Invalid selection." << endl;
    }
}
 
//Reveals the cell at location
//Uses Dan's (killer) recursive function!
void minesweeper::reveal_at(int r, int c) {
    if (r < 0 || c < 0 || r >= row || c >= col) return; //checks for out of bounds
    if (board[r][c].get_exposed() || board[r][c].get_bomb()) return; //stop if is bomb or already exposed
 
    //If the nearby bomb count is zero, we're clear to show ALL surrounding cells
    if (board[r][c].get_bombs_near() == 0) {
        board[r][c].set_exposed(true); //stops recursion from looping back on self
        reveal_at(r - 1, c); //above
        reveal_at(r + 1, c); //below
        reveal_at(r, c - 1); //left
        reveal_at(r, c + 1); //right
        reveal_at(r + 1, c + 1); //up and right
        reveal_at(r - 1, c - 1); //below and left
        reveal_at(r + 1, c - 1); //up and left
        reveal_at(r - 1, c + 1); //below and right
    }
    board[r][c].set_exposed(true); //stops recursion from looping back on self
}
 
ostream &operator<<(ostream & stream, minesweeper &game){
    for (int r = 0; r < game.row; r++) {
        for (int c = 0; c < game.col; c++) {
            stream << game.board[r][c];
        }
        stream << endl;
    }
    return stream;
}
 
//Checks for game over condition: an exposed bomb
bool minesweeper::game_over() {
    int exposed_spaces = 0, flagged_count = 0;
 
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (board[r][c].get_flagged()) {
                flagged_count++;
            }
            if (board[r][c].get_exposed()) {
                exposed_spaces++;
                if (board[r][c].get_bomb()) {
                    cout << "You get nothing. You lose." << endl;
                    return true; //game is over, but you lost
                }
            }
        }
    }
 
    //All cells are exposed except for flagged bombs
    if (exposed_spaces == (row * col - flagged_count)) {
        cout << "You've won! You did it! Oh, I just knew you would." << endl;
        return true; //game is over, and you won
    }
 
    return false; //game is not over yet
}
