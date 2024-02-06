class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        

        int endOfSmaller = -1, endOfLarger = 0;

    
        int curr = INT_MIN;
        int count = 0;

        int ans = 1;
        if(nums.size()<3)
        return nums.size();
        for(int i=0;i< nums.size();i++)
        {
           
            if(nums[i]!=curr)
            {
                curr = nums[i];
                swap(nums[endOfSmaller+1] , nums[i]);

                count = 1;
                ++endOfSmaller;
                endOfLarger = i;
                
            }
            else if(nums[i] == curr)
            {
                if(count<2)
                {
                   swap(nums[endOfSmaller+1] , nums[i]);
                   
                    ++endOfSmaller;
                    endOfLarger = i;
                    
                }
                else
                {
                   ++endOfLarger;
                 
                }
                count++;
            }
        }
        
        return endOfSmaller+1;
    }
};