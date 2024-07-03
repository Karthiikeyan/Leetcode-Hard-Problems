class Solution {
    int n, m;
    int mod = 1e9+7;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    vector<vector<int>> dp;
private:
    int dfs(int row, int col, vector<vector<int>>&matrix){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        long long currLen = 1;
        for(int i=0;i<4;i++){
            int row1 = row + drow[i];
            int col1 = col + dcol[i];
            if(row1 >= n || row1 < 0 || col1 >= m || col1 < 0 || matrix[row][col]>=matrix[row1][col1]) continue;
            currLen += dfs(row1, col1, matrix);
        }
        return dp[row][col] = currLen%mod;
    }
public:
    int countPaths(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.resize(n, vector<int>(m, -1));
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = dfs(i, j, matrix);
                ans += curr;
            }
        }
        return ans%mod;
    }
};