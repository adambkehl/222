Introduction to operator overloading.

```cpp
Person const &Person::operator=(Person const &p){}
```
overloads the = operator, allowing us to:
```cpp
Person p, q, r;
p = q = r;
```
