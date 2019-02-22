#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {

private:
    char *name, *address, *phone;

public:
    friend ostream & operator<<(ostream &, Person const &);
    Person();
    Person(char const *, char const *, char const *);
    ~Person();
    Person const &operator=(Person const &p);
};
