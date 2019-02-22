//------- cell.cpp -------
//#include "minesweeper.h"
 
cell::cell() {
    bombs_near= 0;
    is_flagged = false;
    is_bomb = false;
    is_exposed = false;
}
 
cell::~cell() {}
 
//Setters and getters (used instead of accessing variables directly)
void cell::set_bombs_near(int const bomb_count) { bombs_near = bomb_count; }
int cell::get_bombs_near() const { return bombs_near; }
void cell::set_flagged(bool const flag) { is_flagged = flag; }
bool cell::get_flagged() const { return is_flagged; }
void cell::set_bomb(bool const bomb) { is_bomb = bomb; }
bool cell::get_bomb() const { return is_bomb; }
void cell::set_exposed(bool const expose) { is_exposed = expose; }
bool cell::get_exposed() const { return is_exposed; }
 
//Overloaded << operator used in main:  cout << game;
//Shows entire game board with custom characters
ostream &operator<<(ostream & stream, cell const &current_cell) {
    unsigned char block_character = 178; //block is: 178 "▓"
    unsigned char dot_character = 249; //dot is 249 "∙"
    unsigned char flag_character = 176; //flag is 176 "░" (or maybe 213 "╒"?)
 
    if (current_cell.is_flagged) {
        stream << flag_character;
        return stream;
    }
    if (current_cell.is_exposed) {
        if (current_cell.bombs_near == 0) stream << dot_character;
        else stream << current_cell.bombs_near ;
    }
    else {
        stream << block_character;
    }
 
    return stream;
}
