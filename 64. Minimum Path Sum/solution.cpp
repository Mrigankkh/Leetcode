class Solution {
public:
    int getValue( vector<vector<int>> dp, int x , int y)
    {
        if(x<0 || y<0 || x>= dp.size() || y>= dp[0].size())
        {
            return 201;
        }
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),201));

        // Initialize first element.
        dp[0][0] = grid[0][0];

        // Initialize the first column.
        for(int col = 1; col< grid.size();col++)
        {
            dp[col][0] = grid[col][0] + dp[col-1][0];
        }

        // Initialize the first row.
      for(int row = 1; row< grid[0].size();row++)
        {
            dp[0][row] = grid[0][row] + dp[0][row-1];
        }

        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j< grid[0].size();j++)
            {
               dp[i][j] = grid[i][j]  + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};