#define ll long long int
const int P = 37;
const ll MOD = 1e9+7;

class Solution {
    int n;
    vector<int> dp;
    vector<vector<ll>> hash;
private:
    void preComputeHash(string &s) {
        hash.resize(n);
        for(int i = 0; i < n; i++) {
            ll pwd = 1; // Fixed: Initialize pwd to 1
            ll prefix = 0;
            vector<ll> &computeHash = hash[i];
            for(int j = i; j < n; j++) { // Fixed: Iterate from i to n
                int curr = s[j] - 'a' + 1; // Fixed: Use s[j] instead of s[i]
                prefix = (prefix + (curr * pwd) % MOD) % MOD; // Fixed: Accumulate hash using addition
                computeHash.push_back(prefix);
                pwd = (pwd * P) % MOD;
            } 
        }
    }

    bool isEqual(int l1, int r1, int l2, int r2) {
        int len = r1 - l1 + 1; // Fixed: Calculate length correctly
        if (hash[l1][len-1] == hash[l2][len-1]) { // Fixed: Compare hashes of the correct length
            return true;
        }
        return false;
    }

    int findMax(int ind) {
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int &ans = dp[ind];
        ans = 1;

        for(int i = 1; ind + i < n; i++) { // Fixed: Correct the iteration and indexing
            int l1 = ind, r1 = ind + i - 1;
            int l2 = ind + i, r2 = ind + 2 * i - 1;
            if(r2 >= n) break;
            if(isEqual(l1, r1, l2, r2)) ans = max(ans, 1 + findMax(l2));
        }
        return ans;
    }
public:
    int deleteString(string s) {
        n = s.size();
        dp.resize(n, -1);
        preComputeHash(s);

        return findMax(0);
    }
};
