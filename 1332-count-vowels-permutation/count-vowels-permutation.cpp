class Solution {
private:
    enum vowel {
        a = 0,
        e,
        i,
        o,
        u,
        k,
    };
    const int MOD = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        vector<long> dp0(k, 1);
        vector<long> dp1(k);

        for (int x = 2; x <= n; x++) {
            dp1[a] = (dp0[e] + dp0[i] + dp0[u]) % MOD;  
            dp1[e] = (dp0[a] + dp0[i]) % MOD;           
            dp1[i] = (dp0[e] + dp0[o]) % MOD;           
            dp1[o] = dp0[i];                            
            dp1[u] = (dp0[i] + dp0[o]) % MOD;           
            swap(dp0, dp1);
        }
        
        return (dp0[a] + dp0[e] + dp0[i] + dp0[o] + dp0[u]) % MOD;
    }

};