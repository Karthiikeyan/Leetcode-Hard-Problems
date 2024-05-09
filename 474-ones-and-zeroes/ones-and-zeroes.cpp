class Solution {
    vector<vector<vector<int>>> dp;
private:
    int rec(int level, int n, int m, vector<string> &strs){
        if(level<0){
            return 0;
        }
        if(dp[level][n][m]!=-1) return dp[level][n][m];
        
        int notTake = 0 + rec(level-1, n, m, strs);
        int take = INT_MIN;
        string temp = strs[level];
        int zero = 0, one = 0;
        for(auto str: temp){
            if(str=='0') zero++;
            else one++;
        }
        if(zero<=m && one<=n) take = 1 + rec(level-1, n - one, m - zero, strs);
        return dp[level][n][m] = max(take, notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int siz = strs.size();
        dp.resize(siz, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        return rec(siz-1, n, m, strs);
    }
};