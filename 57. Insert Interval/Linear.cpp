class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int initialIntervalSize = intervals.size();
        if(intervals.size()==0)
        return {newInterval};
        // First we insert this interval into intervals.
   
        for(int i = 0; i<intervals.size(); i++)
        {
            if(newInterval[0]< intervals[i][0])
            {
                intervals.insert(intervals.begin()+i ,newInterval );
                break;
            }
            else if( newInterval[0]> intervals[i][0] && newInterval[0]< intervals[i][1])
            {
                if(intervals[i][1]> newInterval[1])
                {
                    return intervals;
                }
                intervals[i][1] = newInterval[1];
            }

        }

        if(intervals.size() == initialIntervalSize)
        intervals.push_back(newInterval);

        // Resolve conflicts now.

        for(int i=0;i< intervals.size()-1;i++)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                // Conflict
                intervals[i][1] = max(intervals[i+1][1], intervals[i][1]);
                intervals.erase(intervals.begin()+ i+1);
                i--;
            }
          
        }


        return intervals;
    }
};