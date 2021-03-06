#include <iostream>
#include <cstring>
using namespace std;

#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)>(y)?(x):(y))

class Largenumber {
private:
	int * thenumber;
	int size;
public:
	Largenumber();
	Largenumber(int);
	Largenumber(float);
	Largenumber(char const *);
	~Largenumber();
	Largenumber(Largenumber const &); //copy constructor
	Largenumber operator+(Largenumber const &n);
	Largenumber &operator-(Largenumber const &);
	Largenumber &operator++();
	Largenumber &operator++(int);
	Largenumber &operator--();
	Largenumber &operator--(int);
	Largenumber operator=(Largenumber const &);
	bool operator==(Largenumber const &) const;
	bool operator!=(Largenumber const &) const;
	int length(int const) const;
	//friend istream const &operator>>(istream const &, Largenumber const &);
	//friend ostream const &operator<<(istream const &, Largenumber const &);
};
