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
