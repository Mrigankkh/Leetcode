class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
        return false;

        int i = 0;
        int minValue = nums[0];

        while(nums[i+1]<= nums[i] && i< nums.size()-2)
        {   
            minValue = nums[++i];
            if(i+1 >= nums.size())
            return false;
        }
        
       int threshold = nums[++i];
        i++;
        while(i< nums.size())
        {
            if(nums[i] > threshold)
            {
                return true;
            }
            else if(nums[i]> minValue && nums[i] < threshold)
            {
                threshold = nums[i];
            }
            else if(nums[i]< minValue)
            {
                minValue = nums[i];
            }
            i++;
        }
        return false;


       
    }
};