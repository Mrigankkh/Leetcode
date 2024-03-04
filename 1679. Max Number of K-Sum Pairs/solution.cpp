class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(auto n : nums)
        {
            if(umap.find(n)==umap.end())
            {
                umap[n] = 1;
            }
            else
            {
                umap[n]++;
            }
        }
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {

            if(umap[nums[i]]>0)
            {
                    umap[nums[i]]--;
                if(umap[k - nums[i]]>0)
                {
                
                    umap[k-nums[i]]--;
                    ans++;
                }
            }

        }
        return ans;
    }
};