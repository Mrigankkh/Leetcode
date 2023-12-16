class Solution {
public:

    struct compare{

        bool operator()(vector<int> &p, vector<int> &q)
        {
            return p[0]>q[0];
        }
    };
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<2)
        return true;
        priority_queue<vector<int>, vector<vector<int>> , compare> pq;
        for(auto interval : intervals)
        {
            pq.push(interval);
        }
        auto end = pq.top();
        pq.pop();
        while(!pq.empty())
        {

            auto temp = pq.top();
            pq.pop();
            if(temp[0]<end[1])
            {
                return false;
            }
            else
            {
                end = temp;
            }
        }
        return true;
        
    }
};