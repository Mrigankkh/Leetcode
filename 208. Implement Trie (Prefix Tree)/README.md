# Implemetn Trie (Prefix Tree)
<h2>TLDR;</h2>
Fairly straightforward implementation of trees. Make a Node structure that has an array of Nodes and a bool flag.
<h2>Intuition</h2>
A trie is made up of nodes which have the following structure. Each node has an array of links to nodes of size 26 coresponding to each letter of the alphabet. Each node also has a boolean flag that denotes end of word. The trie has a root node. Each time you add a word into a trie, it adds a node character by character if the node for that character int the sequence doesnt already exist.
<h2>Detailed Logic</h2>

<ol>
<li>
<h3>Create the Node</h3>
</li>
<li>
<h3>Insert</h3>
</li>
<li>
<h3>Check if Exists</h3>
</li>
<li>
<h3>Check Prefix</h3>
</li>
</ol>

<h2>Important Points</h2>
<ol>
<li>Lowercasing is important in this question. tolower() function in c++ makes an uppercase character lowercase.</li>
</ol>
