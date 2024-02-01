class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
         vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=0;i<intervals.size();i++)
        {
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];
            if(end > newEnd)
            {
                continue;
            }
            else if(end < newStart)
            {
                ans.push_back({start,end});
                start = newStart;
                end = newEnd;
            }
            else
            {
                end = newEnd;
            }

        }  

        ans.push_back({start,end});
        return ans;       
        
    }
};