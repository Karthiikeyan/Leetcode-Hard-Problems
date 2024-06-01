class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        vector<int> v;
        for(auto it: s){
            v.push_back(it - 'a');
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            ans += abs(v[i] - v[i-1]);
        }
        return ans;
    }
};