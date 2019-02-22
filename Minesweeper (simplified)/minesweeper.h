//------- minesweeper.h -------
//Wrote in class 2/21/19
//Fixed the flood function to match real minesweeper
//Commented anything that wasn't simple or clear
 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
#define EASY 15
#define MED 17
#define HARD 19
 
class cell {
private:
    int bombs_near;
    bool is_flagged, is_exposed, is_bomb;
 
public:
    friend ostream &operator<<(ostream & stream, cell const &c);
    cell();
    ~cell();
    void set_bombs_near(int const c);
    int get_bombs_near() const;
    void set_flagged(bool const b);
    bool get_flagged() const;
    void set_exposed(bool const b);
    bool get_exposed() const;
    void set_bomb(bool const b);
    bool get_bomb() const;
};
 
class minesweeper {
private:
    cell **board;
    int row, col, probability;
 
public:
    friend ostream &operator<<(ostream & stream, minesweeper &m);
    minesweeper();
    ~minesweeper();
    void count_bombs_near();
    bool game_over();
    void reveal_at(int reveal_row, int reveal_col);
    void get_user_move();
    void get_settings();
};
 
