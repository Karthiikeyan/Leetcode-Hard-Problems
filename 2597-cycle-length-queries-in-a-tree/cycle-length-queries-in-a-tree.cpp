class Solution {
private:
    int height(int x){
        int res = 0;
        while(x){
            res++;
            x/=2;
        }
        return res;
    }

    int getParent(int i){
        if(i==1) return -1;
        return i/2;
    }

    int LCA(int x, int y){
        if(height(y)>height(x)){
            swap(x,y);
        }
        int p = height(x)-height(y);
        x=x/pow(2,p);
        while(x!=y){
            x=x/2;
            y=y/2;
        }
        return x;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto query: queries){
            int a = query[0];
            int b = query[1];
            int lca = LCA(a, b);
            ans.push_back(height(a) + height(b) - 2*height(lca) + 1);
        }
        return ans;
    }
};