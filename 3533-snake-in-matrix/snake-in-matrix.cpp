class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) 
    {
        int x = 0;
        vector<vector<int>>dir(110, vector<int>(110));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dir[i][j] = x++;

        int i = 0, j = 0;
        for(auto com:commands)
        {
            if(com == "RIGHT") j++;
            else if(com == "DOWN") i++;
            else if(com == "LEFT") j--;
            else if(com == "UP") i--;
        }
        return dir[i][j];
    }
};