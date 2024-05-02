class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int fresh_orange = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j]==1)
                    fresh_orange++;
            }
        }

        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, -1, 0, 1};
        int max_time = 0;
        int cnt = 0;
    
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            max_time = max(max_time, time);
            
            for(int i=0;i<4;i++){
                int row1 = row + drow[i];
                int col1 = col + dcol[i];
                if(row1>=0 && row1<n && col1>=0 && col1<m && grid[row1][col1]==1){
                    grid[row1][col1] = 2;
                    q.push({{row1, col1}, time + 1});
                    cnt++;
                }
            }
        }
        if(cnt==fresh_orange) return max_time;
        return -1;
    }
};