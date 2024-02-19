class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int i = 0;
        int ans = nums.size()+1;
        int j = 0;
        while(i<=j && i< nums.size() && j<nums.size())
        {
            while(sum< target && j<nums.size()-1)
            {
                
                sum+= nums[++j];
            }          
            while( sum >= target && i<=j)
            {
            ans = min(ans , j-i+1);

                sum-= nums[i];
                ++i;

                
            }
            if(j==nums.size()-1)
            break;
         
        }
        if(ans== nums.size()+1)
        return 0;
           return ans;
    }
};