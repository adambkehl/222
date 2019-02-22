# Blackjack
### Allocating and deallocating memory manually

Allocating space for the 2D array using the *new* keyword
(Used in the constructor)
```cpp
players = new int *[NPLAYERS];
for (int i = 0; i < NPLAYERS; i++) {
  players[i] = new int[5];
}
```

Deallocating space for the 2D array using the *delete* keyword
(Used in the deconstructor)
```cpp
for (int i = 0; i < NPLAYERS; i++) {
  delete[] players[i];
}
delete[] players;
```
