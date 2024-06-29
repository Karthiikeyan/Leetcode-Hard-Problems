class Solution {
    vector<int> temp;
    vector<vector<int>> ans;
    bool safe(int col,int row){
        if(col==1) return true;
        for(int i=0;i<temp.size();i++) {
            int c = i+1,r = temp[i];
            if((r == row) || ((row - r) == (col-c)) || ((col-c == (r-row)))) return false;
        }
        return true;
    }
    void fun(int n,int ctr){
        if(ctr>n) ans.push_back(temp);
        for(int i=1;(ctr<=n) &&  i<=n;i++) {
            if(safe(ctr,i)){
                temp.push_back(i);
                fun(n,ctr+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        fun(n, 1);
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans = nQueen(n);
        vector<vector<string>> result;
        int N = ans.size();
        for(int k=0;k<N;k++){
            vector<string> temp;
            for(int i=0;i<n;i++){
                string s = "";
                for(int j=1;j<=n;j++){
                    if(j==ans[k][i]) s += 'Q';
                    else s += '.';
                }
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }
};