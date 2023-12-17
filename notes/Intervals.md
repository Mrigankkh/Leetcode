#Interval Patterns


<h1>Important Points</h1>
<ol>
  <li>Almost always require sorting the intervals either based on start times or on end times</li>
  <li>Typically O(nlogn)</li>
</ol>

<h1>Edge Cases</h1>
<ol>
  <li>No intervals</li>
  <li>One interval</li>
  <li>Two intervals</li>
  <li>Complete overlapped interval</li>
  <li>Duplcate interval</li>
</ol>

<h1>Sorting</h1>
Use the STL to sort. <br/>

```

bool compareSecondElement(vector<int>& a, vector<int>& b) { 
    return a[1] < b[1];
} 
sort(intervals.begin(), intervals.end(), compareSecondElement);

```
