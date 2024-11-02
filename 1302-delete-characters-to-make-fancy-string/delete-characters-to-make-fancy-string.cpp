class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string temp = "";
        temp += s[0];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt = 1;
            if(cnt < 3) temp += s[i];
        }
        return temp;
    }
};