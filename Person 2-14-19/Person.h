#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> //not <string.h>
using namespace std;

class Person
{
private:
    char *name;
    char *address;
    char *phone;
public:
    Person();
    ~Person();
    Person(char const *n, char const *a, char const *p);
    void printPerson(Person const &p);
    char const *getName() const;
    char const *getAddress() const;
    char const *getPhone() const;
    Person const &operator=(Person const &p);
};
