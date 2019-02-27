#include "Largenumber.h"

int main() {
	return 0;
}

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

Largenumber Largenumber::operator+(Largenumber const &number) {
	int carry = 0, sum;
	Largenumber result((float)(MAX(size, number.size)));

	for (int i = 0; i < MIN(size, number.size); i++) {
		sum = *(thenumber + i) + *(number.thenumber + i) + carry;
		*(result.thenumber + i) = sum % 10;
		carry = sum / 10;
	}

	if (size < number.size) {
		for (int i = size; i < number.size; i++) {
			sum = *(number.thenumber + i) + carry;
			*(result.thenumber + i) = sum % 10;
			carry = sum / 10;
		}
	}

	if (size > number.size) {
		for (int i = number.size; i < size; i++) {
			sum = *(thenumber + i) + carry;
			*(result.thenumber + i) = sum % 10;
			carry = sum / 10;
		}
	}

	if (carry == 0) {
		return result;
	} else {
		Largenumber resized_number = ((float)(result.size + 1));
		for (int i = 0; i < result.size; i++) {
			*(resized_number.thenumber + i) = *(resized_number.thenumber + i);
			*(resized_number.thenumber + result.size) = carry;
		}
		return resized_number;
	}
}

Largenumber::Largenumber(float number) {
	size = (int)(number);
	thenumber = new int[size];
	for (int i = 0; i < size; i++) {
		*(thenumber + i) = 0;
	}
}

bool Largenumber::operator!=(Largenumber const & number) const {
	if (size != number.size) return true;
	else {
		for (int i = 0; i < size; i++) {
			if (thenumber[i] != number.thenumber[i]) return true;
		}
	}
	return false;
}

bool Largenumber::operator==(Largenumber const &number) const {
	if (size != number.size) return false;
	else {
		for (int i = 0; i < size; i++) {
			if (thenumber[i] != number.thenumber[i]) return false;
		}
	}
	return true;
}

Largenumber Largenumber::operator=(Largenumber const &number) {
	if (*this != number) {
		delete[] thenumber;
		size = number.size;
		thenumber = new int[size];
		for (int i = 0; i < size; i++) {
			thenumber[i] = number.thenumber[i];
		}
	}
	return *this;
}
/*
ostream &(ostream & stream, Largenumber const &number) {
	for (int i = number.size - 1; i >= 0; i--) {
		stream << number.thenumber[i];
	}
	stream << endl;
	return stream;
}
*/
