class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;

        for(int i=1;i< nums.size();i++)
        {
            nums[i] = nums[i-1] + nums[i];
        }

        int ans = 0;
        for(auto num : nums)
        {
            if(num==k)
            {
                ans++;
            }
            if(umap.find(num - k)!=umap.end())
            {
                ans+=umap[num - k];
            }
             umap[num]++;
          
        }
        return ans;

    }
};