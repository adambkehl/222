#include <iostream>
using namespace std;

void display(int, int);

int main() {
	int hour, minute;
	cout << "Enter the number of hours: ";
	cin >> hour;
	cout << endl << "Enter the number of minutes: ";
	cin >> minute;
	display(hour, minute);
}

void display(int h, int m) {
	cout << "Time: " << ":" << m << endl;
}
