class Solution {
     private int bsearch(int start, int end, int[] nums, int target)
    {



        while(start<= end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid]==target)
            {
             return mid;  
            }
            else if(nums[mid]> target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;

    }
    public int search(int[] nums, int target) {
       int start = 0;
       int end = nums.length-1;

       if(nums.length== 1 || nums[start]< nums[end])
       {
            return bsearch(start,end,nums,target);
       } 

        // We need to find the pivot
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid+1]< nums[mid])
            {
                //mid is the largest element, mid+1 is the start of the pivoted array.

                if(target> nums[nums.length-1])
                {
                  return  bsearch(0, mid, nums, target);
                }
                else
                {
                  return  bsearch(mid+1, nums.length-1, nums, target);
                }
            }
            else if(nums[start]> nums[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
return -1;
    }
}