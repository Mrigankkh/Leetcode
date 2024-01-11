# Subarray Sum Equals K
<h2>TLDR;</h2>
Prefix Sum + Hashmap. Create a prefix sum array and hash each value in it as you see it while searching for k - prefixArray[i] for each i.
<h2>Intuition</h2>
We need to find the sum of subarrays. Sum of a subarray from i to j is total_sum_till[j] -  total_sum_till[i]. For this, think prefiux sum. We need to find (i,j)s where total_sum_till[j] -  total_sum_till[i] = k. If we had this total_sum_till value stored somehow, we can use this to add to the answer. We can use hashmaps for this.
<h2>Detailed Logic</h2>
The first part of this problem is creating a prefix array. Each element prefixArray[i] =  prefixArray[i] + sum_till[i].
<br/>
In the next part, for every element in this prefix array, we store its frequency in a hashmap. This indicates how many subarrays ending before the current index have the cumulative sum {key} . We find if prefixArray[i] - nums exists in this frequency map and if so, with what frequency. We add this frequency to our final answer. 
<br/>


<h2>Important Points</h2>
1. Use hashmaps.