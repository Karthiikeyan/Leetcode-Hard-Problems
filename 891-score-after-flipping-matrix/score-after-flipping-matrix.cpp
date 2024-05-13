class Solution {
private:
    int binaryToDecimal(string n) 
    { 
        string num = n; 
        int dec_value = 0; 
    
        // Initializing base value to 1, i.e 2^0 
        int base = 1; 
    
        int len = num.length(); 
        for (int i = len - 1; i >= 0; i--) { 
            if (num[i] == '1') 
                dec_value += base; 
            base = base * 2; 
        } 
    
        return dec_value; 
    }

public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        for(int j=1;j<m;j++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) cnt++;
            }
            if(cnt > n/2){
                for(int i=0;i<n;i++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<m;j++){
                temp += to_string(grid[i][j]);
            }
            ans += binaryToDecimal(temp);
        }
        return ans;
    }
};