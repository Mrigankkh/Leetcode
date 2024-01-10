class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> umap;
        for(auto i: nums)
        {
            if(umap[i])
            return true;
            umap[i]= true;
        }
        return false;
    }
};x