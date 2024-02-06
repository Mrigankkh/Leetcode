# Remove Duplicates from Sorted Array II

<h2>TLDR;</h2>
QuickSort-esque logic. 2 pointer problem, maintain 1 pointer for the end of a valid subarray from 0 -> i and one pointer for end of the invalid subarray from (i+1 -> j)

<h2>Intuition</h2>
When you see in-place and sorting, think Quick Sort. Quicksort sorts an array in-place. An important property of quick sort due to which that style of a 2 pointer solution works in this problem that it partitions the array seen so far into 2 arrays, one with elements lesser than pivot and one with elements greater than pivot. We can modify this partition defination and follow a new partition defination that says: <b>" Everything in the first partition is a valid subarray and everything in the right partition is invalid." </b>
</br>
In conclusion, when you need to have some kind of a sorted output with an in-place restriction, QuickSort or a similar 2 pointer "divide-the-array-into-2" is a good bet.

<h2>Detailed Logic</h2>
Think of the problem as dividing the entire array into 2 subarrays: the first subarray is the one with the correct and the required output and the second is all other elements.( This is borrowed from Quicksort algorithm) <br> 

To do this, we maintain 2 pointers i and j, denoting the ends of each subarray. We know that the second subarray starts immediately after the first subarray ends. So, the ranges of the 2 subarrays are:
SubArray 1: (0, i)
SubArray 2: (i+1, j)
<br>
Assume we are currently looking at element at index x. If this is a valid element (it has occured at most 1 time before), we need to insert this element into SubArray1. Since we know that the entire array is sorted, we need to insert it at the end of SubArray[1]. We do this by simply swapping Array[x] with Array[i+1]. This valid element is in the corrrect position. We increment the index i. 
<br/>
If we encounter an element that is invalid, it  goes into SubArray2 at the end. Since it is the last of the 2 subarrays, we can simply increment the index j.

At the end we return the size of the first subarray which we get from i+1.


<h2>Important Points</h2>
1. Make sure you take values of elements that you need before swapping.
2. Since pointers are being incremented, keep IndexOutOfBounds errors in mind.


