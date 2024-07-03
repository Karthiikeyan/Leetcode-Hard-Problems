class Solution {
private:
    vector<int> topoSort(vector<vector<int>>&adj){
        int n = adj.size();
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> topo;

        for(int i=0;i<n;i++){
            for(auto node: adj[i]){
                indeg[node]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                int node = q.front();
                q.pop();
                topo.push_back(node);
                for(auto child: adj[node]){
                    indeg[child]--;
                    if(indeg[child]==0) q.push(child);
                }
            }
        }
        if(topo.size()!=n) return {};
        return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjA(k), adjB(k);
        int x, y;

        int n1 = rowConditions.size();
        for(int i=0;i<n1;i++){
            x = rowConditions[i][0];
            y = rowConditions[i][1];
            adjA[x-1].push_back(y-1);
        }

        int n2 = colConditions.size();
        for(int i=0;i<n2;i++){
            x = colConditions[i][0];
            y = colConditions[i][1];
            adjB[x-1].push_back(y-1);
        }

        vector<int> row = topoSort(adjA);
        vector<int> col = topoSort(adjB);
        if(row.size()==0 || col.size()==0) return {};

        vector<int> mpp(k, 0);
        for(int i=0;i<col.size();i++){
            mpp[col[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int t=0;t<row.size();t++){
            int val = row[t] + 1;
            int i = t;
            int j = mpp[row[t]];
            ans[i][j] = val;
        }
        return ans;
    }
};