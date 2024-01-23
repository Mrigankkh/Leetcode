class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {


        vector<int> dp(nums.size(),1);
        dp[nums.size()-1] = 1;
        return optim(nums,nums.size()-2,dp);
    }

    int optim(vector<int>& nums , int end , vector<int>& dp)
    {

        for(int i= nums.size()-2; i>=0;i--)
        {
         
            for(int j = i+1 ; j< nums.size();j++)
            {
                if(nums[j]> nums[i])
                {
                      dp[i] = max(dp[i],1+ dp[j]);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
    }

    int brute(vector<int>& nums , int start , int mini)
    {
        
        if(start>=nums.size())
        return 0;

        if(nums[start]<=mini)
        return brute(nums , start+1 , mini);
    
        return max(1 + brute(nums , start+1 , nums[start]) , brute(nums , start+1 , mini));

    }
};