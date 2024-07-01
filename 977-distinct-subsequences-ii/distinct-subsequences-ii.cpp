class Solution {
public:
    int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        vector<int> vis(26, -1);
        int total =  0;
        int curr = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int ind = ch - 'a';

            if(i == 0){
                vis[ind] = 1;
                total = 1;
                curr = 1;
                continue;
            }

            curr = 1 + total;
            if(vis[ind]==-1)
                total = (curr + total) % MOD;
            else
                total = (((total + curr)%MOD) - vis[ind])%MOD;
            
            vis[ind] = curr;
        }     
        if(total < 0) return total + MOD;
        return total;   
    }
};