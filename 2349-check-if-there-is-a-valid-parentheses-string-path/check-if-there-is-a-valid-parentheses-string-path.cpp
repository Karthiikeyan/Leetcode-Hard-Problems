class Solution {
    int dp[101][101][201];
    int n, m;
private:
    bool dfs(int row, int col, int len, vector<vector<char>>& grid){
        if(row==n-1 && col==m-1)
            return len==0;
        if(len < 0) return false;
        if(dp[row][col][len]!=-1) return dp[row][col][len];

        bool right = false, down = false; 
        if(row+1<n) right = dfs(row+1, col, (grid[row+1][col]=='(') ? len+1 : len - 1, grid);
        if(col+1<m) down = dfs(row, col+1, (grid[row][col+1]=='(') ? len+1 : len - 1, grid);
        return dp[row][col][len] = right || down;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        return dfs(0, 0, grid[0][0]=='(' ? 1 : -1, grid);
    }
};