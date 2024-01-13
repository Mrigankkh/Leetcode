# Reorganizing Sting
<h2>TLDR;</h2>
Alternatively place most frequent elements using priority queue.
<h2>Intuition</h2>
First part of this problem involves understanding how we can identify strings that can be reorganized and how to reorganize them. A string cannot be reorganized if two characters will be adjacent in all possible combinations. This happens when there is a high frequency of 1 character in the string. On further inspection, it happens when I character makes up more than half the string. So now we can identify invalid strings using this condition!
<br/>
Next part of the question involves reorganizing. Here, the intuition lies in thinking about the worst case. In the worst case, we would have half our string made up of one character. In order to place these characters in the string, we would need to place this particular character alternatively.That is the solution.
<br/>
To place them alternatively, we would need to know their frequencies, and at every point, we should have the character with the max frequency. Since we need this repeatedly, and possibly need to update this as well, priority queues qould be a good data structure for this problem.


<h2>Detailed Logic</h2>
The first step is to obtain the frequencies of characters in the priority queue. Get the frequencies using a vector and push them into the priority queue.<br/>
Pop the top element of the queue based on this frequency. If the character popped is the same as last one in result string, pop another. Add this to the string, decrease the freuency and push it back in the queue.


<h2>Important Points</h2>
<ol>
<li>You need to check the last character of the result string while appending a new character from the priority queue. If the character is the same as that in the string, pop another character from the priority queue.</li>
<li>Understand working with multiple elements of a priority queue. This is a classic case where just popping the first element is not enough,there are problems where you need to pop out elements in the queue till you get the desired element and then push them back in.</li>
</ol>
