class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int v=graph.size();

        queue<pair<int,int>>q;

        for(int i=0;i<v;i++){
            q.push({i,1<<i});
        }
        int viss=(1<<v)-1;
        vector<vector<bool>>vis(v,vector<bool>(viss+1,false));
        for(int i=0;i<v;i++){
            vis[i][1<<i]=true;
        }
        int path=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto temp=q.front();
                q.pop();
                int node=temp.first;
                int mask=temp.second;

                if(mask==viss) return path;

                for(auto i:graph[node]){
                    int nxt=mask|(1<<i);

                    if(vis[i][nxt]) continue;
                    if(nxt==viss) return path+1;
                    q.push({i,nxt});
                    vis[i][nxt]=true;
                }
            }
            path++;
        }
        return -1;
    }
};