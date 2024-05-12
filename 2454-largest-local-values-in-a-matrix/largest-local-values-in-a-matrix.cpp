class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n-2, vector<int>(n-2, 0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int maxi = -1e9;
                for(int row=i;row<i+3;row++){
                    for(int col=j;col<j+3;col++){
                        maxi = max(maxi, grid[row][col]);
                    }
                }
                v[i][j] = maxi;
            }
        }
        return v;
    }
};