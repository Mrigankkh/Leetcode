class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp = {};
        for(int i=1;i<= nums.size();i++)
        {

            temp.push_back(nums[i-1]);

            if(i%3==0)
            {
               
                if(temp[2] - temp[0] <=k)
                {
                        ans.push_back(temp);
                }
                temp = {};
            }
        }
        if(ans.size()== nums.size()/3)
        return ans;
        return {};
        
    }
};