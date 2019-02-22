#include <iostream>
using namespace std;

int main() {
	int rows = 0, count = 0;
	cout << "Enter number of rows: ";
	cin >> rows;
	count = rows;

	for (int i = 0; i < rows; i++) {
		count--;
		for (int j = count; j > 0; j--) cout << ".";
		for (int k = rows - count; k > 0; k--) cout << "#";
		cout << endl;
	}

	cin.get(), cin.get();
}
