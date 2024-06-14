class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> mpp;
        for(auto it: t) mpp[it]++;

        int i = 0, j = 0;
        int cnt = 0, ans = 1e9;
        int stInd = 0;
        while(j < n){
            if(mpp[s[j]] > 0) cnt++;
            mpp[s[j]]--;

            while(cnt==m){
                if(j - i + 1 < ans){
                    ans = j - i + 1;
                    stInd = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }
        if(ans==1e9) return "";
        return s.substr(stInd, ans);
    }
};