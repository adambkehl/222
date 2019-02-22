#include "Sudoku.h"
int main(int argc, char *argv[])
{
	Sudoku puzzle;
	/*
	if (argc == 1)
		puzzle.genPuzzle(1);
	else*/

	puzzle.genPuzzleFromFile(argv[1]);
	
	puzzle.printPuzzle();
	puzzle.solve();
	puzzle.printPuzzle();

	cout << "Program exited solve.";
	cin.get(), cin.get();
}
