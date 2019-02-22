# Assignment #3
### Page 377 #10
Passes the ```add()``` function as an argument to ```calculate()```
Calculate calls add within it and returns the value.

### Page 444 #1
Basic function overloading within a class

### Page 446 #6
When the code is executed, the compiler chooses what function to call depending on the data type.
For integer arrays, the compiler chooses the template, which is written so that any number type is supported (int, double, etc)
For string arrays (2D arrays), it chooses the ```char* maxn()``` function, passing it the 2D array by reference: ```**arrayElements``` instead of passing it like arrayElements[][] because their was an error.
