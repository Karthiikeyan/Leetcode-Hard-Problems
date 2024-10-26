class Solution {
private:
    bool valid(int r, int c, char val, vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[r][i]==val) return false;
            if(board[i][c]==val) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(int k='1';k<='9';k++){
                        if(valid(i, j, k, board)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};