#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define SIZE 9

class Sudoku {
private:
	int **grid;
public:
	Sudoku();
	~Sudoku();
	void genPuzzleFromFile(char *fname);
	void printPuzzle();
	bool const isValidRow(int x, int y, int value);
	bool const isValidCol(int x, int y, int value);
	bool const isValidBox(int x, int y, int value);
	bool const isValid(int x, int y, int value);
	bool const solve();
};
