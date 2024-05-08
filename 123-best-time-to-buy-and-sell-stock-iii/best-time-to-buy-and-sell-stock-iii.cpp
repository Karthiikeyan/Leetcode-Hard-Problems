class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        vector<vector<int>> dp(k+1, vector<int>(n, 0));

        for(int i=1;i<=k;i++){
            int maxDiff = -prices[0];
            for(int j=1;j<n;j++){
                dp[i][j] = max(dp[i][j-1], prices[j]+maxDiff);
                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
};