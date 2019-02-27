#include <iostream>
#include <cstring>
using namespace std;

class Largenumber {
private:
	int * thenumber;
	int size;
public:
	Largenumber();
	Largenumber(int);
	Largenumber(char const *);
	~Largenumber();
	Largenumber(Largenumber const &); //copy constructor
	Largenumber &operator+(Largenumber const &);
	Largenumber &operator-(Largenumber const &);
	Largenumber &operator++();
	Largenumber &operator++(int);
	Largenumber &operator--();
	Largenumber &operator--(int);
	Largenumber &operator=(Largenumber const &);
	bool &operator==(Largenumber const &) const;
	bool &operator!=(Largenumber const &) const;
	int length(int const) const;
	friend istream const &operator>>(istream const &, Largenumber const &);
	friend ostream const &operator<<(istream const &, Largenumber const &);
};
