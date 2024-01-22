class Solution {
public:
    vector<vector<int>> ans;
    void combinationSumHelper(vector<int>& candidates, int target, vector<int> curr, int prev)
    {
        if(target == 0)
                {
                    ans.push_back(curr);
                }
        else if(target<2)
        {
            return;
        }

        for(auto cand: candidates)
        {
            vector<int> temp = curr;
            if(cand<= target && cand>= prev)
            {
                temp.push_back(cand);
                combinationSumHelper(candidates, target - cand ,  temp, cand);
    
            }
        }
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
      combinationSumHelper(candidates, target, {}, INT_MIN);
       return ans;
    }
};