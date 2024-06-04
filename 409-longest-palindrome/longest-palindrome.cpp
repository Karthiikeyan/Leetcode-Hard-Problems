class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> umap;
        int l = s.length();
        if (l == 1)
        return l;
        for (int i = 0; i < l; i++) {
            umap[s[i]]++;
        }
        unordered_map<char, int> :: iterator it;
        int q{};
        int a{};
        for (it=umap.begin(); it!=umap.end(); it++){
            if ((it->second)%2!=0 & a==0){
                a=1;
            }
            q+=((it->second)/2)*2;
        }
        return q+a;
    }
};