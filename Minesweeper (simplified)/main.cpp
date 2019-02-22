//------- main.cpp -------
//#include "minesweeper.h"
 
int main(int argc, char **argv) {
 
    srand((unsigned int)time(0)); //seed random num generator
 
    minesweeper game;
    game.count_bombs_near(); //calculates bombs near every piece
 
    while (!game.game_over()) {
        system("cls"); //windows only, mac is:  system("clear");
        cout << game;
        game.get_user_move();
    }
 
    cin.get(), cin.get();
    return 0;
}
