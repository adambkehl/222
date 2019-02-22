#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T>
T maxn(T arrayElements[], T intsInArray) {
	int biggestIndex = 0;
	for (int i = 1; i < intsInArray; i++) {
		if (arrayElements[i] > arrayElements[biggestIndex]) biggestIndex = i;
	}
	return arrayElements[biggestIndex];
}

char* maxn(char **arrayElements, int intsInArray) {
	int biggestIndex = 0;
	for (int i = 1; i < intsInArray; i++) {
		if (strlen(arrayElements[i]) > strlen(arrayElements[biggestIndex])) biggestIndex = i;
	}
	return arrayElements[biggestIndex];
}

int main(int argc, char **argv) {

	int a[] = { 100, 200, 300, 120, 30 };
	cout << maxn(a, 5) << endl;

	char **strings;
	strings = new char*[5];
	for (int i = 0; i < 5; i++) {
		strings[i] = new char[12];
	}
	strcpy(strings[0], "Hi");
	strcpy(strings[1], "Hello");
	strcpy(strings[2], "Yes");
	strcpy(strings[3], "Goodbye");
	strcpy(strings[4], "Adios");

	cout << maxn(strings, 5) << endl;

	cin.get(), cin.get();
}
