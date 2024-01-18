# Binary Tree Vertical Order Traversal

<h2>TLDR;</h2>
BFS.
<h2>Intuition</h2>
You need to traverse the entire tree; so its either DFS or BFS. You need a columnwise sorting i.e. an element closer to root should come before one thast farther away. Thus BFS makes more sense.

<h2>Detailed Logic</h2>
You need to know the horizontal level of every node that you encounter. The root node's horizontal level is initialized as 0, anything to its left is curr - 1, to its right is curr + 1. For all such levels, we need an array with elements in that level. Since we are doing BFS, we are guarenteed that elements will be vertically sorted. If we add left element before right in the queue, the array will also be horizontally sorted. 
<br/> We store a key value pair of this {vertical_level, array} that we later output.
<br/>
While doing BFS, we push the node as well as its level in the queue. When we pop this pair, we add the value of the node to the respective array using the level as the key.
<br/>
One challenge we encounter here is outputting the answer. When using unordered maps, we cannot guarentee that the keys are sorted. If we sort these keys, our time complexity would take a hit. Instead, just maintain a max and a min for the maximum level and the minimum levels encountered.
<br/>
Run a loop between the maximum and the minimum and if an array exists for that level in the unordered map, push that to the final answer.
<br/>
Time Complexity: O(N)

<h2>Important Points</h2>
<ol>
<li>Case when theres no root</li>
<li>Ordered maps have time complexity log(n) for search.</li>
<li>make_pair</li>
<li>Carefully chose between BFS and DFS</li>
</ol>
