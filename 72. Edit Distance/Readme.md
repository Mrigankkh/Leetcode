<h1>Edit Distance</h1>
<h2>TLDR;</h2>
Keep one string as is and try all operations on each charecter of the other string
<h2>Intuition</h2>


<h2>Detailed Logic</h2>
1. Denote strings in terms of indexes.
    i: String s     j: String t
    Let f(i,j) be this function acting on substrings of s and t from s[0,i] and t[0,j]

2. Explore all possibilities
    2.1 If s[i] ==t[j], we do not need to change anything if both charecters are the same.

    2.2 If s[i]!= t[j], we have 3 options: 
        2.2.1 Insert a character in front of S
                1 + f(i,j-1)
        2.2.2 Delete a character in S
                1 + f(i-1,j)
        2.2.3 Replace
                1 + f(i-1, j-1)

3. Take minimum of 2.2.1, 2.2.2, 2.2.3

4. Base cases:
    4.1 If i<0, it means we cannot convert any more characters. If j>0, we must add the remaining characters.
    4.2 If j<0, it means there are extra characters; we can delete. 

<h2>Important Points</h2>
1. This problem was a DP problem since it requires performing essentially the same operation on different inputs

2. Base cases.

