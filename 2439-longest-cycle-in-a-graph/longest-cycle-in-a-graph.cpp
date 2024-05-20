class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>indeg(n);
        vector<int>vis(n);
        
        for(int i=0; i<n; i++){
            if(edges[i] != -1) indeg[edges[i]]++;
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            vis[top] = 1;
            q.pop();
            if(edges[top] != -1){
                indeg[edges[top]]--;
                if(indeg[edges[top]] == 0) q.push(edges[top]);
            }
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int start = i;
                int curr = edges[i];
                vis[i] = 1;
                int c = 0;
                
                while(curr != start){
                    if(indeg[curr] == 0) break;
                    curr = edges[curr];
                    vis[curr] = 1;
                    c++;
                }
                ans = max(ans,c+1);   
            }
        }
        return ans;
    }
};
