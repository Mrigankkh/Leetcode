<h1>Non-overlapping Intervals</h1>
<h2>TLDR;</h2>
Sort intervals based on end and greedily remove the interval with longest end inc case of conflict.
<h2>Intuition</h2>
Most intervals questions require sorting. It makes sense to sort in the direction of iteration since at each point, we do not care about the start of the interval; clashes can be determined based on when the interval is ending. 
<br/>
*** End of the interval determines if it clashes with the next in line interval. ***
<br/>
Now that we have sorted intervals, in case of clashes, it would make sense to remove the inteval with the shortest end time (GREEDY) . This way it is less likely to clash in the future with other intervals.

<h2>Detailed Logic</h2>
Step 0: Sort<br/>
We must sort the array first as is the case in most interval based questions. It makes sense to sort the array based on the end because the end determines if the interval is in a conflict. </br>
Step 1: Find the overlap.</br>
After sorting, if the next interval has a start time lesser than the end time of the previous interval, it means there is a clash.</br>
Step 2: Figure out which side of the overlap to remove</br>
Remove the second overlapping interval. This is because we are removing interval that clashes but also has the highest end time.</br>
Step 3: Propogate</br>
We only need to return the count. 
To "remove" this interval, we can store the previous end in a variable. If an element is removed, it means the previous end is the end of the first interval in the clash. We ca store this in a previousEnd variable and update it each time there is no conflict.

<h2>Important Points</h2>
<ol>
<li>Comparator for sorting using STL. Method if decalred should be outside the solution class.</li>
<li>It is important to understand how to sort i.e. based on the start or the end.</li>
<li>This problem appears to be a good candidate for a DP solution at first glance. However, it can be solved EASILY with a greedy approach.</li>
</ol>
