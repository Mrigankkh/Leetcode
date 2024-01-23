class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size() , vector<int> (triangle.size(), 10000));

        // Write the base case for the last element of triangle.
        for(int i=0;i< triangle[triangle.size()-1].size(); i++)
        {
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
        }
       
        //Now iterate

        for(int height = triangle.size() -2 ; height>=0 ; height-- )
        {
            for(int width = 0;width<= height; width++)
            {
                dp[height][width] = triangle[height][width] + min(dp[height+1][width], dp[height+1][width+1]);
            }
        }

        return dp[0][0];
    }
};