#include <iostream>
using namespace std;

double add(double x, double y);
double calculate(double a, double b, double(*add)(double, double));

int main() {
	double firstNum, secondNum;

	for (int i = 1; i <= 3; i++) {
		cout << "(" << i << "/3 loop iterations)" << endl;
		cout << "Enter your first number: "; cin >> firstNum;
		cout << "Enter your second number: "; cin >> secondNum;
		cout << "Combined is: " << calculate(firstNum, secondNum, add) << endl << endl;
	}
	cout << "Press enter to exit.";
	cin.get(), cin.get();
	return 0;
}

double add(double x, double y) {
	return x + y;
}

double calculate(double a, double b, double (*add)(double, double)){
	return (*add)(a, b);
}
