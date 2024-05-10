class Solution {
    int n;
private:
    int rec(int l, int r, string s){
        int res = 0;
        while(l>=0 && r<n){
            if(s[l]==s[r]) res++;
            else return res;
            l--, r++;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += rec(i, i, s);
            ans += rec(i, i+1, s);
        }
        return ans;
    }
};