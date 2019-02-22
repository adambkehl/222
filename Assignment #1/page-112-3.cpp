#include <iostream>
using namespace std;

int main() {
	double degrees, arc_minutes, arc_seconds;
	cout << "Enter a latitude in degrees, minutes, and seconds:";
	cout << endl << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> arc_minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> arc_seconds;

	cout << degrees << " degrees, " << arc_minutes << " minutes, " << arc_seconds << " seconds = " << degrees + arc_minutes/60 + arc_seconds/60/60 << " degrees";
	cin.get(); cin.get();
}
