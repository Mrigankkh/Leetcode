class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int sub = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(!(nums[i]==0 || nums[i] - sub<=0))
            {
                sub+=nums[i]-sub;
                ans++;
            }
           

        }
        return ans;
    }
};