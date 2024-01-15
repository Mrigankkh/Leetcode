class Solution {
public:

       
        int dp(vector<int>& nums, int i, vector<int>& umap)
        {
            if(i>=nums.size()) return 0;
            if(umap[i]!=-1)return umap[i];
            return  umap[i] = max(nums[i] + dp(nums,i+2, umap),   dp(nums,i+1, umap));
            

        }
    int rob(vector<int>& nums) {
        vector<int> umap (nums.size()+1 , -1);
        return dp(nums , 0 , umap);
    }
};
