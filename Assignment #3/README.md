# Assignment #3
### Page 377 #10
Passes the ```add()``` function as an argument to ```calculate()```
Calculate calls add within it and returns the value.

### Page 444 #1
Basic function overloading within a class

### Page 446 #6
When the code is executed, the compiler chooses what function to call depending on the data type.
For integer arrays, the compiler chooses the template, which is written so that any number type is supported (int, double, etc)

For string arrays (2D arrays), it chooses the ```char* maxn()``` function, passing it the 2D array by reference: ```**arrayElements``` instead of like arrayElements[][] because their were errors calculating string length.

The templated function finds the largest integer in the array and the second function finds the longest string in the array


This is basically how strlen works:
```cpp
 int my_strlen(char * str)
{
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}
```
