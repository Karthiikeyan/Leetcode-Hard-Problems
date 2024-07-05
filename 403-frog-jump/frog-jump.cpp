class Solution {
public:
    bool solve(int index , vector<int>& stones ,int n, int k,  map<pair<int,int>,bool>& dp ){
        if(index>=n) return false;
        if(index==n-1) return true;
        if(dp.find({index,k})!=dp.end()){
            return dp[{index,k}];
        }
        bool ans = false;
        for(int i = max(k-1,1) ; i<=min(k+1,n-1);i++){
            int j=index;
            while(j<n && stones[index]+i>stones[j]) j++;
            if(j<n && stones[index]+i==stones[j]) {
               ans = ans || solve(j,stones,n,i,dp);
            }
        }
        return dp[{index,k}] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<pair<int,int>,bool> dp;
        return solve(0,stones, n , 0,dp);
    }
};