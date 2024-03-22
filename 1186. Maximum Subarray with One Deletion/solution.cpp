class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> left(nums.size());
    
        vector<int> right(nums.size());
        if(nums.size()==1)
        return nums[0];
        int maxSum = INT_MIN;
        int currEndingAt = 0;
        for(int i =0;i< nums.size();i++)
        {
            currEndingAt= max(currEndingAt+ nums[i], nums[i]);
         
            left[i] = currEndingAt;
            maxSum =max(maxSum,currEndingAt);
        }
         currEndingAt = 0;
        for(int i =nums.size()-1;i>=0;i--)
        {
          
            currEndingAt= max(currEndingAt + nums[i], nums[i]);
            right[i] = currEndingAt;
        }

        for(int i=0;i< nums.size()-2;i++)
        {
            maxSum = max(maxSum ,  left[i]+ right[i+2]);
        }
        return maxSum;

    }
};