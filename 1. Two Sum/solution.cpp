class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Create the map of the form value, index
    
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++)
        {   
            //Search element should be target - nums[i]
            int search = target - nums[i];
            if(umap.find(search)!=umap.end())
            {
                //element is found
                return {i , umap[search]};
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};