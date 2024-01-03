class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int l = 1, r = 1;
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {

            ans[i] = l *ans[i];
            l = l*nums[i];
            ans[nums.size()-1-i] = r * ans[nums.size()-i-1];
            r = r*nums[nums.size()-1-i];

            
        }

        
        return ans;
    }
};

