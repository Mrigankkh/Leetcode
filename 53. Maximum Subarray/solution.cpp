class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Kadane's Algorithm

        int mx = INT_MIN;
        int sum = 0;
        if(nums.size()==1)
        return nums[0];


        for(auto i : nums)
        {
            sum+=i;
            if(sum>mx)
            {
                mx = sum;
            }
            if(sum<0)
            sum = 0;
        }

        return mx;
    }
};