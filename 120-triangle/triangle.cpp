class Solution {
    vector<vector<int>> dp;
    int rec(int i, int j, int n, vector<vector<int>>& triangle){
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans1 = triangle[i][j] + rec(i+1, j, n, triangle);
        int ans2 = triangle[i][j] + rec(i+1, j+1, n, triangle);
        return dp[i][j] = min(ans1, ans2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n, vector<int>(n, -1));
        return rec(0, 0, n, triangle);
    }
};