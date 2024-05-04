class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&grid, int n, int m){
        grid[row][col] = 1;
        if(row-1>=0 && grid[row-1][col]==0)
            dfs(row-1, col, grid, n, m);
        if(row+1<n && grid[row+1][col]==0)
            dfs(row+1, col, grid, n, m);
        if(col-1>=0 && grid[row][col-1]==0)
            dfs(row, col-1, grid, n, m);
        if(col+1<m && grid[row][col+1]==0)
            dfs(row, col+1, grid, n, m);
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==0) dfs(i, 0, grid, n, m);
            if(grid[i][m-1]==0) dfs(i, m-1, grid, n, m);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==0) dfs(0, j, grid, n, m);
            if(grid[n-1][j]==0) dfs(n-1, j, grid, n, m);
        }

        int ans = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    ans+=1;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};