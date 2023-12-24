<h1>FindMinimum in Rotated Sorted Array</h1>
<h2>TLDR;</h2>
If sorted array is rotated, tis first element is going to be larger than last element. Find this sub-array in a merge sort-esque fashion until the unsorted element is found.
<h2>Intuition</h2>
The question explicitly mentions the time complexity to be O(logn). This tells us that we cannot traverse throught the entire array. We need to kepp splitting arrays into 2 sub arrays in a merge sort-esque fashion till we find the element that is larger than its next element (i.e. unsorted).

<h2>Detailed Logic</h2>
The condition for an array to be sorted and rotated is that its first element is greater than its last element and at some point between there exists an element that is larger than its next element. This is assuming that the array is rotated (ie. not the original sorted array, in which casew the smallest element will simply be the first element).
Additionally, we know that there is only one kink in this sorted array.

We first check if the entire array satisfies this condition. If so, we check the first half of this array has this kink. If so, we recursively split this array in half. This is because the kink must be present in one of the two split arrays.
</br>
I defined a function getMin. If the middle element of the array is greater than the next element, the kink is found! I return the next element. If not, I check the left half and then the right half of the array. 


<h2>Important Points</h2>
<ol>
<li>Sorted Array + O(logN) is a very strong indicator of Binary Search. It is the solution in almost all such cases.</li>
</ol>
