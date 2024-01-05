# Two Sum

<h1>TLDR;</h1>

If the target element is T, we need to find a T- nums[i] for any 1 nums[i]. Use hash maps. Edge case: repeated elements.

<h1>Intuition</h1>
Fairly straightforward intuition.

<h1>Detailed Logic</h1>
Initialize an empty hashmap. This hashmap must be of the form <i><value, index></i>. Parse through the array. At each iteration, calculate T-nums[i] and check if it exists in the hashmap. If it does, return the relevent indices, if not, update the map to store value and index of the current element.


<h1>Important Points</h1>

<ol>
<li>Edge case: Repeated Elements. Ex: target 6 with array [3,3]. We need to use hash maps carefully</li>
</ol>
