class Solution {
public:
    vector<string> printVertically(string str) {
        vector<string> s;
        string curr = "";

        vector<string> ans;
        int n = str.size(), N = 0;
        for(int i=0;i<n;i++){
            if(str[i]==' '){
                s.push_back(curr);
                curr = "";
            }else curr += str[i];
        }
                
        if(!curr.empty()) s.push_back(curr);
        for (const auto& str : s) {
            N = max(N, static_cast<int>(str.size()));
        }
        n = s.size();
        for(int i=0;i<N;i++){
            string temp = "";
            for(int j=0;j<n;j++){
                if(i < s[j].size()){
                    temp += s[j][i];
                }else
                    temp += ' ';
            }
            while(!isalpha(temp.back())) temp.pop_back();
            ans.push_back(temp);
        }
        return ans;
    }
};