#include "Person.h"

int main() {
    Person p("name", "phone", "address");
}
Person const &Person::operator=(Person const &p) {
    if (this != &p) {
        delete[]name;
        delete[]phone;
        delete[]address;
        name = new char[strlen(p.name) + 1];
        address = new char[strlen(p.address) + 1];
        phone = new char[strlen(p.phone) + 1];
    }
    return *this;
}

ostream &operator<<(ostream &out, Person const &p) {

    return ( out << "name: " << p.name << endl << "phone: " << p.phone << endl << "address: " << p.address << endl );
}

Person::Person() { }
Person::~Person() { }
Person::Person(char const *a, char const *b, char const *c) {
    name = new char[10];
    phone = new char[10];
    address = new char[10];
}
