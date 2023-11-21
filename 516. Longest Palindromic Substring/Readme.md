<h1>Longest Palindromic Substring</h1>
<h2>TLDR;</h2>
Each individual character is a palindrome; expand outwards.
<h2>Intuition</h2>
Every string of length is a palindrome. To check all possible substrings that may be palindromes, we can expand outwards in both directions for each character in the string until the palindrome condition breaks. (It is true for the string of length 1 , we then check for a string of length 3 and so on).

<h2>Detailed Logic</h2>
The brute force approach would require us to generate all substrings and check palindrome condition on each substring. This has a O(n^3) time complexity. 
The above logic will combine the tarversing and palindrome check to alleviate this to O(n^2).
We need to expand on both sides from each character i. 

for(i = 0 --> s.length)
expand(s,i)

We also need to account for palindromes of even length. We can think of this as expanding from 2 characters.

for(i = 0 --> s.length)
expand(s,i,i) // for odd length
expand(s,i,i+1) // for even length

<h2>Important Points</h2>
Indexing errors.

We need to return the substring, so we need to ensure that the expand method returns a relevent index or value. In my implementation, I have returned the length of the substring and used that to derive the start and the end index. I change these indices everytime the length is greater than the current length.