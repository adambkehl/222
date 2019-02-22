#include "Person.h"

int main() {
    Person y("John", "Palomar", "7603301782");
    Person z, x, a;
    z.printPerson(y);
    a = x = z = y;
}

Person::Person(){}

Person::Person(char const *n, char const *a, char const *p) {

    name = new char[strlen(n) + 1];
    address = new char[strlen(a) + 1];
    phone = new char[strlen(p) + 1];

    strcpy(name, n);
    strcpy(address, a);
    strcpy(phone, p);
}

void Person::printPerson(Person const &p) {
    Person x;
    x = p; //overloaded
    cout << x.getName() << endl;
    cout << x.getAddress() << endl;
    cout << x.getPhone() << endl;
}

Person const &Person::operator=(Person const &p) {
    if (this != &p) {
        delete[]name;
        delete[]phone;
        delete[]address;
        name = new char[strlen(p.getName()) + 1];
        address = new char[strlen(p.getAddress()) + 1];
        phone = new char[strlen(p.getPhone()) + 1];
    }
    return *this;
}

char const *Person::getName() const {return name;}
char const *Person::getAddress() const {return address;}
char const *Person::getPhone() const {return phone;}

Person::~Person() {
    delete[]name;
    delete[]address;
    delete[]phone;
}
