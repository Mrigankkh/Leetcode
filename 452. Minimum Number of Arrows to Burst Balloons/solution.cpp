bool compare (vector<int> p , vector<int> q)
    {
        return p[1] < q[1];
    }
class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 2)
        return points.size();
        sort(points.begin(),points.end(), compare);
        int ans = 0;
         long int currEnd = LONG_MIN;
        for(int i=0;i< points.size();i++)
        {
            if(points[i][0]> currEnd) 
            {
                ans++;
                currEnd = points[i][1];
            }
        }
        return ans;
    }
};