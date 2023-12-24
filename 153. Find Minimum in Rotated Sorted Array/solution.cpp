class Solution {
public:

    bool sorted(int a , int b)
    {
        return a<b;
    }
    int getMin(vector<int>& nums, int start, int end)
    {
        int mid =( start + end )/2;
    
        if(nums[mid] > nums[mid+1])
        {
            return nums[mid+1];
        }
        else if(!sorted(nums[start], nums[mid]))
        {
            // rotation is here.
            return getMin(nums, start, mid);

        }
        else if(!sorted(nums[mid+1], nums[end]))
        {
          return  getMin(nums,mid+1,end);
        }

return -1;
        
    }

    int findMin(vector<int>& nums) {
         int len = nums.size();
        if(nums.size()==1 || nums[0]< nums[len-1])
        {
            return nums[0];
        }
        return getMin(nums, 0, len-1);
       
        
     

    }
};