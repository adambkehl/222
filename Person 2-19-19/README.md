Introduction to operator overloading.

### The = operator:

```cpp
Person const &Person::operator=(Person const &p){}
```
overloads the = operator, allowing us to:
```cpp
Person p, q, r;
p = q = r;
```

### The << operator:
```cpp
ostream &operator<<(ostream &out, Person const &p) {}
```
overloads the << operator, allowing us to:
```cpp
Person p;
cout << p;
```
