class Solution {
public:
     unordered_map<int,bool> reach;
    bool canReach(int index, vector<int>& nums)
    {
        if(reach.find(index)!=reach.end())
        return reach[index];
        bool ans = false;
        for(int i = index+1; i<= index + nums[index] && i<nums.size(); i++)
        {
            ans = ans || canReach(i,nums);
        
        }
        reach[index] = ans;
        return ans;

    }
    bool canJump(vector<int>& nums) {
         reach[nums.size()-1] = true;
         return canReach(0,nums);
    }
};