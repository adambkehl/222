#include "Sudoku.h"
int main(int argc, char *argv[]) {
	Sudoku puzzle;
	puzzle.genPuzzleFromFile(argv[1]);	
	puzzle.printPuzzle();
	puzzle.solve();
	puzzle.printPuzzle();

	cout << "Program exited solve.";
	cin.get(), cin.get();
}
