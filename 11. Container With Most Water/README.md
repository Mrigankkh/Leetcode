# Container with Most Water

<h2>TLDR;</h2>
2 pointers, one at start one and end of array. Increment in direction of smaller height[i] and calculate area.

<h2>Intuition</h2>
It is tough to think of this greedy approach. However, we can notice that it is not possible to traverse the array from left to right, since nothing can be said about the area until all elements are seen. We can in this case consider traversing the array "inwards" .

<h2>Detailed Logic</h2>
This problem has a greedy solution. We use 2 pointers; keep one at the index 0 and 1 at index 'size-1'. The crux of this problem lies in realising that we can only find 2 indices with a larger area than the current one by replacing the smaller of the 2 sides in search for a larger side. We keep traversing the array inwards from the direction of the smaller side and recording the maximum area.


<h2>Takeaways</h2>
<ol>
<li>In array questions when traversing the array from left to right doesnt make sense because the answer cannot be computed independently for a particular index and the merged/added/compared later on with the final answer, and you must acheive O(N), consider traversing the array using 2 pointers either "inwards" or "outwards".</li>
</ol>
