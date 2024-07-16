class Solution {
    vector<int> path;
    vector<int> crossPath;
    vector<vector<int>> g;
private:
    void dfs(int node, string &s){
        int &curr = path[node];
        curr = 1;
        vector<int> vals;
        for(auto child: g[node]){
            dfs(child, s);
            if(s[child]==s[node]) continue;
            curr = max(curr, path[child]+1);
            vals.push_back(path[child]);
        }
        sort(vals.begin(), vals.end());
        int n = vals.size();
        if(n>1){
            crossPath[node] = vals[n-1] + vals[n-2] + 1;
        }
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        g.resize(n);
        path.resize(n, 0);
        crossPath.resize(n, 0);

        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                g[parent[i]].push_back(i);
            }
        }

        dfs(0, s);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, max(path[i], crossPath[i]));
        }
        return ans;
    }
};