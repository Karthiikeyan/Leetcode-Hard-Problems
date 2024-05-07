class Solution {
    int N;
    vector<int> ans, count;
    vector<vector<int>> adj;

private:
    void dfsRoot(int node, int par){
        for(auto child: adj[node]){
            if(child!=par){
                dfsRoot(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfsChild(int node, int par){
        for(auto child: adj[node]){
            if(child!=par){
                ans[child] = ans[node] - count[child] + (N - count[child]);
                dfsChild(child, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        ans.resize(n, 0);
        count.resize(n, 1);
        adj.resize(n);

        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfsRoot(0, -1);
        dfsChild(0, -1);
        return ans;
    }
};