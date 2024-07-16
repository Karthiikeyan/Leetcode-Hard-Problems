class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size();

        for(char i='a';i<='z';i++){
            int lastCh = n + 1;
            for(int j=0;j<n;j++){
                if(s[j]==i) lastCh = j;
                int startInd = lastCh;
                if(startInd <= j) ans += (startInd + 1);
            }
        }
        return ans;
    }
};