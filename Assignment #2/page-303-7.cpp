#include <iostream>
#include <string>
using namespace std;

int main() {
	string words = "";
	int vowels = 0, consonants = 0, others = 0;
	char c;
	cout << "Enter words (q to quit): ";
	do {
		cin >> words;

		if (isalpha(c = words[0])) {
			if (c == 'a' || c == 'e' || c == 'i' ||
				c == 'o' || c == 'u' || c == 'A' ||
				c == 'E' || c == 'I' || c == 'O' ||
				c == 'U')
				vowels++;
			else consonants++;
		} else {
			others++;
		}
	} while (words != "q");
	consonants--;

	cout << endl
		<< "Vowels: " << vowels << endl
		<< "Consonants: " << consonants << endl
		<< "Others: " << others << endl;

	cin.get(), cin.get();
}
