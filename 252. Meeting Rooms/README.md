#Meeting Rooms

<h1>TLDR;</h1>

Sort the intervals

<h1>Intuition</h1>

Looking at the problem and the constraints, we can easily identify the brute force solution; its going to be (n^2) wherein for every interval, we chek if there exists another clashing interval.

We need to loop throught the entire intervals vector once i.e. we need to look at all intervals. This will take O(n). Where we can optimize is the second part, which is checking if for an interval, there exists a clashing interval.

If all intervals were sorted based on their start, we only need to compare the start if one interval and the end of previous interval to check for clashes. This way, checking for clashes is O(1).

<h1>Detailed Logic</h1>

We need to sort the intervals so that finding clashing intervals takes O(n) time, however the sorting itself takes O(nlogn) time. We first sort this interval. I have used priority queues. I insert each interval into a priority queue and then pop them out one by one and check for clashes between the current interval and the previously popped interval.

 The insertion of intervals takes O(n) * O(logn) which is O(nlogn) time.
 
 Popping each interval has worst case time complexity of O(n).

 Overall time complexity becomes O(nlogn) which is faster than the brute force approach of (n^2).

Another approach could be to define a vector of size 10^6 and mark all the scheduled durations. This was time complexity would be O(n) however, space complexity would also be O(n)

Important Points

<ol>
<li>Comparator for the priority queue.</li>
<li>Sorting using STL would require lesser code.</li>
</ol>
