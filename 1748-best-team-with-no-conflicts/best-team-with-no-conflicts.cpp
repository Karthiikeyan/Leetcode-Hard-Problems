class Solution {
    vector<vector<int>> dp;
    vector<pair<int,int>> players;
private:
    int rec(int ind, int last){
        if(ind<0) return 0;
        if(dp[ind][last]!=-1) return dp[ind][last];

        int notTake = rec(ind-1, last);
        int take = 0;
        if(players[ind].first==players[last].first){
            take = players[ind].second + rec(ind-1, ind);
        }else if(players[ind].first<players[last].first && players[ind].second<=players[last].second){
            take = players[ind].second + rec(ind-1, ind);
        }
        // cout<<take<<" "<<notTake<<" "<<ind<<endl;
        return dp[ind][last] = max(take, notTake);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        for(int i=0;i<n;i++){
            players.push_back({ages[i], scores[i]});
        }
        players.push_back({1e9,1e9});
        sort(players.begin(), players.end());
        dp.resize(n+1, vector<int>(n+1, -1));
        return rec(n-1, n);
    }
};