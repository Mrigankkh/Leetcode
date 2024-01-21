# Valid Sudoku

<h2>TLDR;</h2>
Look at each condition seperately, for the last condition of box, do a BFS for each box to see if an element is repeated in that box.

<h2>Intuition</h2>
There are 3 conditions given clearly. We need to satisfy each condition. The first two are straightforward. Maintain a vector for 