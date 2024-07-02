class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();

        int ind = 0;
        bool isFirst = true;
        for(int i=0;i<n2;i++){
            if(p[i]=='*'){
                if(isFirst){
                    p[ind++] = p[i];
                    isFirst = false;
                }
            }else{
                p[ind++] = p[i];
                isFirst = true;
            }
        }

        vector<vector<bool>> dp(n1+1, vector<bool>(ind+1, 0));
        if(ind > 0 && p[0]=='*')
            dp[0][1] = true;
        dp[0][0] = true;

        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n1][ind];
    }
};