#include "Largenumber.h"

Largenumber::Largenumber() {
	thenumber = new int[1];
	*thenumber = 0; // thenumber[0] = 0;
	size = 1;
}

Largenumber::Largenumber(int number) {
	int tempLength = length(number);
	size = tempLength;
	thenumber = new int[tempLength];
	//storing in reverse for easier modifiying
	for (int i = 0; i < tempLength; i++) {
		*(thenumber + i) = number % 10;
		number /= 10;
	}
}

Largenumber::Largenumber(char const * num) {
	size = strlen(num);
	thenumber = new int[size];
	for (int i = 0; i < size; i++) {
		*(thenumber + i) = *(num + size - i - 1) - '0';
		//*(thenumber + i) -> thenumber[i]
	}
}

Largenumber::~Largenumber() {
	delete[] thenumber;
}

Largenumber::Largenumber(Largenumber const & number) {
	size = number.size;
	thenumber = new int[size];
	for (int i = 0; i < size; i++) {
		*(thenumber + i) = *(number.thenumber + i);
	}
}

int Largenumber::length(int const number) const {
	int tempNumber = number;
	int length_of_number = 0;
	while (tempNumber != 0) {
		tempNumber /= 10;
		length_of_number++;
	}
	return length_of_number;
}

Largenumber & Largenumber::operator+(Largenumber const &number) {
	int carry = 0;
	int sum;
	//working on...
}
