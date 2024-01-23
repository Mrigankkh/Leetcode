class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));

        //Initialize the first element.
        if(obstacleGrid[0][0]==1)
        return 0;
        dp[0][0] = 1;

        //Initialize the first row.

        for(int col = 1; col< m;col++)
        {
            if(obstacleGrid[col][0] == 1)
                {
                    dp[col][0] = 0;
                }
            else
                dp[col][0] = min(dp[col-1][0], 1);
        }

        //Initialize columns.

        for(int row = 1; row< n; row++)
        {
            if(obstacleGrid[0][row] == 1)
                {
                    dp[0][row] = 0;
                }
            else
                dp[0][row] = min(dp[0][row-1],1);
        }

        for(int i= 1; i < m ; i++ )
        {
            for(int j = 1 ; j < n ; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};