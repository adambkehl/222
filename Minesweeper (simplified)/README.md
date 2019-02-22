# Minesweeper (simplified)
![Minesweeper screenshot](https://i.imgur.com/yABV22R.png)

### Changes
* The variables and function names were really confusing and didn't quite line up with what they did.
* i.e. *update_board* only calculates the nearby bombs for each cell, therefore it should be named something like *count_bombs_near*
* Also, the nested loops was confusing for me, so I simplified the counting of the nearby bombs
* Using i, j, k, l is a preference, but I like them to all have names or at least be r and c for row and column
* Simple character embedding in the << overload to display the solid characters or dot. Reference http://www.asciitable.com/ to change them.
* If a cell has 0 surrounding bombs, we can safely show all surrounding cells
* Changed door, danger_flag, and bomb_flag, to is_exposed, is_flagged, and is_bomb.
