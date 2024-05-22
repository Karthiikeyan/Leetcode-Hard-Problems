class Solution {
public:
    int minCut(string str) {
        if (str.length() == 0) {
            return 0;
        }

        vector<int> cut(str.length());
        vector<vector<bool>> isPal(str.length(), vector<bool>(str.length(), false));
        for (int i = 1; i < str.length(); i++) {
            int minVal = i;
            for (int j = 0; j <= i; j++) {
                if (str[i] == str[j] && (i <= j + 1 || isPal[i - 1][j + 1])) {
                    isPal[i][j] = true;
                    minVal = min(minVal, j == 0 ? 0 : 1 + cut[j - 1]);
                }
            }
            cut[i] = minVal;
        }
        return cut[str.length() - 1];
    }

    vector<vector<string>> partition(string s) {
        unordered_map<int, vector<vector<string>>> dp;
        return partitionUtil(s, dp, 0);
    }

private:
    vector<vector<string>> partitionUtil(string s, unordered_map<int, vector<vector<string>>>& dp, int start) {
        if (start == s.length()) {
            vector<string> r;
            return {r};
        }

        if (dp.find(start) != dp.end()) {
            return dp[start];
        }

        vector<vector<string>> words;
        for (int i = start; i < s.length(); i++) {
            if (!isPalindrome(s, start, i)) {
                continue;
            }
            string newWord = s.substr(start, i - start + 1);
            vector<vector<string>> result = partitionUtil(s, dp, i + 1);
            for (vector<string> l : result) {
                vector<string> l1 = {newWord};
                l1.insert(l1.end(), l.begin(), l.end());
                words.push_back(l1);
            }
        }
        dp[start] = words;
        return words;
    }

    bool isPalindrome(string str, int r, int t) {
        while (r < t) {
            if (str[r] != str[t]) {
                return false;
            }
            r++;
            t--;
        }
        return true;
    }
};