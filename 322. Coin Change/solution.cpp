class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        unordered_map<int, int> dp;
        dp[0] = 0;
        for(auto coin : coins)
    {  
        if(coin<= 10000)
          dp[coin] = 1;
    }
        int ans =  ccHelper(coins,amount, dp);
        if(ans== 10001)
        return -1;
        return ans;
    }

    int ccHelper( vector<int>& coins,int amount , unordered_map<int, int>& dp)
    {
        if(amount<0)
        {
            return 10001;
        }

        if(dp.find(amount)!=dp.end())
        {
         return dp[amount];
        }
         dp[amount] = 10001;   
        for(auto coin : coins)
        {
            if(coin<amount)
            dp[amount] = min(dp[amount] ,1+ ccHelper(coins, amount- coin, dp));

        }

        return dp[amount];

        

    }
};