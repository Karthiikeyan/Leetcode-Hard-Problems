#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<ll>> adj(n);
        for(auto road: roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        vector<ll> arr;
        for(auto it: adj){
            arr.push_back(it.size());
        }
        sort(arr.begin(), arr.end(), greater<ll>()); 

        ll ans = 0;
        for(auto it: arr){
            ans += (it*n);
            n--;
        }
        return ans;
    }
};