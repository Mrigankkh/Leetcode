# Maximum Subarray with One Deletion

<h2>TLDR;</h2>
use Kadane's algorithm to get max_till for each element once from the right side once from the left.

<h2>Intuition</h2>
It is at the core a problem of finding maximum subarry so think Kadane's algorithm. The key to solving this problem is understanding that Kadane's algorithm keeps track of the maximum subarray ending at an index. 
<br/>
So if we know the maximum subarray ending at index i and by applying this algorithm backwards on the array, we know maximum subarray starting from index i+2, we can try to find the maximum sum by findig the max combination of left[i] and right[i+2]
<h2>Detailed Solution</h2>