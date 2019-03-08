#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <time.h>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <vector>
using namespace std;
using namespace cv;
#define NPLAYERS 4

template <class T>
class Property {
public:
	Property();
	~Property();
private:
	T type;
	T rent[6];
	T color[3];
	T cost_house;
	char name[80];
	T cost_property;
	T houses, hotel;
	Point vertices[2];
	T player[NPLAYERS];
};

template <class T>
class Board {
private:
	Property <T> space[40];
	int die1, die2;
public:
	Board();
	~Board();
	set_property();
};


class Player {
private:
	int money;
	Point position;
	vector <Property<int>> owned_properties;
	bool in_jail, get_out_jail;
};
