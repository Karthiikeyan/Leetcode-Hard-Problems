class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        if(m == 1 && n == 1) return matrix[m-1][n-1];
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            dp[m - 1][j] = matrix[m - 1][j];
        }
        
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = INT_MAX, diago_left = INT_MAX, diago_right = INT_MAX;
                down = matrix[i][j] + dp[i + 1][j];
                if (j + 1 < n) {
                    diago_right = matrix[i][j] + dp[i+1][j+1];
                }
        
                if (j - 1 >= 0) {
                    diago_left = matrix[i][j] + dp[i + 1][j - 1];
                }
                
                dp[i][j] = min(down, min(diago_left, diago_right));
                
                if (i == 0) {
                    minSum = min(minSum, dp[i][j]);
                }
            }
        }
        
        return minSum;
    }
};