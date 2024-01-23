class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

            unordered_map<string, bool> umap;
            for(auto word : wordDict)
                umap[word] = true;

            unordered_map<int , bool> dp;
            return wbHelper(s,0,umap,dp);
    }


    bool wbHelper(string s,int start, unordered_map<string,bool>& umap, unordered_map<int , bool>& dp)
    {

        if(dp.find(start)!=dp.end())
        return dp[start];
        if(start==s.length())
        return true;

        for(int i = start ;  i < s.length();i++)
        {
            string temp = s.substr(start , i - start +1);
            if(umap.find(temp)!=umap.end())
            {
                // S(start , i) is true. Need ot check f
                if(wbHelper(s, i + 1 , umap, dp))
                {
                    dp[i+1] = true;
                    return true;
                }
            }
        }
        dp[start] = false;
        return false;

    }
};