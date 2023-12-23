<h1>Group Anagrams</h1>
<h2>TLDR;</h2>
All words that are anagrams are same when sorted. They also have same letter count. Sort then match.

<h2>Intuition</h2>
We need to either match words based on their sorted strings or on their letter count. We make this choice by considering time complexity. 

<h2>Detailed Logic</h2>
The sorting option would require O(klogk) time for sorting where k is the length of the largest word. Sorting for each word would require O(N)* O(klog(k)) = O(Nklog(k)). 

Letter count approach would require us to iterate over all strings which is O(N), iterate over all characters of the word to get count which is O(k) where k is the length of the largest word. Next we would need to 'pattern match' based on the letter counts of each words. The straight forward way is to have all patterns stored in a vector and iterate through that vector. This would require O(N) thus making the time complexity O(kN^2). This approach can be optimized by using a string pattern instead of a vector based hot encoded pattern. This way, we can use hash maps with string keys to mitigate the O(N) pattern matching complexity.

Initially I went with the second approach however I did not use string keys and I got TLE. The second approach is straightdforward in terms of implementation. Sort each word and use it as a key in the pattern hashmap.


<h2>Important Points</h2>
<ol>
<li>Consider time complexity</li>
<li>If you get a TLE, try to find the choke point.</li>
<li>While searching/ pattern matching, if your pattern is a map or a vector, see if you can convert this pattern into a string that can directly be used as a key in a hashmap.</li>
</ol>
