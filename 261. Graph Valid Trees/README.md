# Graph Valid Trees

<h2>TLDR;</h2>
Tree : Acyclic + Connected. Check this property using DFS. Make sure each node is seen only once in a <b>path </b>.

<h2>Intuition</h2>
Using the property of trees we need to make sure that the graph is connected and acyclic. To traverse this tree, we can use DFS or BFS however DFS looks to be the easier option since we want to traverse paths. 
<br/>
It is trivial to check if the graph is connected. If at the end of DFS, all nodes are seen, it is connected.
<br/>
The next question that arises is, how do we ensure that the graph is acyclic. We can say that a graph contains cycles if we encounter the same node twice in a same path i.e. we need to ensure that a node isnt visited twice in a path. We can do this by storing all nodes in that path in some data structure.

<h2>Detailed Logic</h2>
Perform a simple DFS on this graph with some slight additions. Additionally, keep track of the number of nodes visited so as to check the connected property.
<br/> 
The modification to DFS here is that we need to maintain a path visited array just like a visited array. At any point, if we encounter a node that is path visited, it means a cycle is detected and we return false. In my implementation, I make count -1 since I am also using it to check connectivity. Once a path is traversed and you are backtracking, keep making pathVisited of the current node while backtracking false; it might be in another path as well.

<h2>Important Points</h2>
<ol>
<li>We are checking 2 conditions, visited and pathVisited. We need to check pathVisited condition first.</li>
</ol>
