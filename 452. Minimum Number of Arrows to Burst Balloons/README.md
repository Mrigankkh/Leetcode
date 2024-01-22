# Minimum Number of Arrows to Burst Balloons

<h2>TLDR;</h2>
Sort based on xend
<h2>Intuition</h2>
Clearly an interval scheduling problem. First thing to do in any such problem is to sort the intervals. Here, sorting by end makes sense because we want to make sure that for every balloon we traverse, the previous balloons cannot exist ahead of them.

<h2>Detailed Solution</h2>
This problem has a greedy solution. Sort the ballons based on their xend. Compare the xend of a ballon with subsequent xstart until xstart>xend. At this point, it means that you have traversed all balloons that 1 arrow can pop. Increment your answer and start traversing further.
 <h2>Important Points</h2>
 <ol>
 <li>Edge cases here was INT_MIN to INT_MAX range. In such a case use long int</li>
 <li>When 49/50 test cases pass, it means code is working as designed and the issue must be with a constraint. Check each constraint of the problem thoroughly.</li>
 </ol>