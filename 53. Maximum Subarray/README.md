# Maximum Subarray
<h2>TLDR;</h2>
Kadane's Algorithm: Keep a running sum and a maximum. Each time sum is negative, change sum to 0. Update maximum if sum is greater than maximum.

<h2>Intuition</h2>
Tough to come up with this solution intuitively. Kadane's Algorithm works best.

<h2>Detailed Logic</h2>
The principal logic to the solution of this problem is <i>"adding negative to anything makes it smaller"</i> We need to parse through the entire array and store the sum up until the sum becomes negative. At this point, the subarray would contribute negatively to the next element i.e. the sum of this subarray plus the next element would be smaller. Each time the running sum of the subarray becomes negative, just replace it with 0. 
<br/>
Parelelly, we need to keep track of the maximum sum we have acheived. We do this using an integer 'mx'. Everytime a sum is greter than mx, we update the sum.8

<h2>Important Points</h2>
1. Kadane's algorithm.