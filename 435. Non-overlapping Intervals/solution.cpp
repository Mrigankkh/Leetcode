bool compare(vector<int>& a , vector<int>& b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /**
        Step 0: Sort
        Step 1: Find the overlap.
        Step 2: Figure out which side of the overlap to remove
        Step 3: Propogate
        **/
        sort(intervals.begin(),intervals.end(),compare);
        int ans = 0;
        int previousEnd = INT_MIN; 
        
        for(int i=0;i<intervals.size();i++)
        {
        
           if(previousEnd>intervals[i][0])
           {
               ans++;
           }
           else
           {
               previousEnd = intervals[i][1];
           }
           
        }
        return ans;

        
    }
};