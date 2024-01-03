# Contains Duplicate
<h2>TLDR;</h2>
Hashmaps for frequency
<h2>Intuition</h2>
Need to store a key-value pair of the form <i>(int)Number : (boolean) seen-before</i>
We use maps for this.
<h2>Detailed Logic</h2>
Use maps. Store number as you see them in the map. If number exists in map, return false.

<h2>Important Points</h2>
1. Use hashmaps.