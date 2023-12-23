#Rotate List

<h1>TLDR;</h1>

Find the length of the list; connect first and last elements (to form a circular queue) and break from the relevant point.

<h1>Intuition</h1>

Linked Lists have only 1 operation: traversal to the next node. They support going to the next node or changing the next node. It is clear that only 2 nodes here change: the node from where the list is rotated and the last element of the newly rotated list.

<h1>Detailed Logic</h1>

The logic of the solution is creating a circular list by connecting the last element and the first element and making the 'next' of the last element of the rotated list pointing to NULL.
</br>
In my implementation, I first find the length of the linked list and find the last element of the rotated list which is (Length - k)th element. I make the next element to this NULL and the next element of the last element of this list as head.

<h1>Important Points</h1>

<ol>
<li>Whenever youre dealing with rotations of lists or circular lists, keep track of case when rotate amount is larger than the list size. In such a case, a % mod may be required.</li>
<li>Null pointer exceptions when dealing with linked lists.</li>
</ol>
