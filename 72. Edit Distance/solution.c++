class Solution {
public:

    int md(string word1 , string word2 , int i, int j , vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 1+ max(i,j);
        if(dp[i][j])
             return dp[i][j];
        if(word1[i] == word2[j])
            return dp[i][j] = md(word1,word2,i-1,j-1,dp);
        else
        
            return dp[i][j] =  1+ min(md(word1,word2,i-1,j,dp), min(md(word1,word2,i,j-1,dp), md(word1,word2,i-1,j-1,dp)));
        
    }
    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n));
        return md(word1,word2,m-1,n-1,dp);

    }
};