Sudoku::Sudoku() {
	grid = new int*[SIZE];
	for (int i = 0; i < SIZE; i++) grid[i] = new int[SIZE];
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			grid[x][y] = 0;
}

Sudoku::~Sudoku() {
	for (int i = 0; i < SIZE; i++) delete[] grid[i];
	delete[] grid;
}

void Sudoku::genPuzzleFromFile(char *fname) {
	ifstream inputFile;
	inputFile.open(fname);
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			inputFile >> grid[i][j];
	inputFile.close();
}
//void Sudoku::genPuzzle(int level) {}
void Sudoku::printPuzzle() {
	cout << "------------------\n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "|" << grid[i][j];
		}
		cout << "|" << endl;
	}
	cout << "------------------\n";
}
bool const Sudoku::isValidRow(int x, int y, int value) {
	for (int i = 0; i < SIZE; i++) {
		if (y != i && grid[x][i] == value)
			return false;
	}
	return true;
}
bool const Sudoku::isValidCol(int x, int y, int value) {
	for (int i = 0; i < SIZE; i++) {
		if (x != i && grid[i][y] == value)
			return false;
	}
	return true;
}

bool const Sudoku::isValidBox(int x, int y, int value) {
	int box, row, col;
	
	row = (x / 3) * 3;
	col = (y / 3) * 3;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (i != x && j != y)
				if (grid[i][j] == value)
					return false;
		}
	}
	return true;
}
bool const Sudoku::isValid(int x, int y, int value) {
	if (isValidRow(x, y, value) &&
		isValidCol(x, y, value) &&
		isValidBox(x, y, value))
		return true;
	return false;
}
bool const Sudoku::solve() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (grid[i][j] == 0) {
				for (int k = 1; k <= SIZE; k++) {
					if (isValid(i, j, k)) {
						grid[i][j] = k;
						if (solve()) return true;
						else grid[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}
