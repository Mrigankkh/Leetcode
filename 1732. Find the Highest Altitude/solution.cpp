class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int current = 0;
        for(int i=0;i<gain.size();i++)
        {
            current+=gain[i];
            ans = max(ans,current);
        }
        return ans;
    }
};