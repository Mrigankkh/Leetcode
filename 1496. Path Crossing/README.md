#Path Crossing

<h1>TLDR;</h1>

Hash the coordinates.

<h1>Intuition</h1>

Clue: The quesiton mentions coordinates. 
Need to check if a coordinate is visited or not so, we need to map the coordinate to a variable visited.

<h1>Detailed Logic</h1>

As per the question, we start from origin (even if it is not mentioned, we can assume this since it will not make a difference). We keep track of the movements and edit our coordiantes accordingly. 
<br/>
To keep track of if a coordinate is visited or not, we use a hashmap with the coordinate as the key. To do this, we can convert the coordinate into a string and use this string key.


<h1>Important Points</h1>

<ol>
<li>If you need to hash a vector/map/etc key, check if it can be converted to a string which can be used as the hashkey</li>
</ol>
