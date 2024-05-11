class Solution {

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;

        for(int up=0;up<n;up++){
            vector<int> colSum(m, 0);
            for(int down=up;down<n;down++){
                for(int j=0;j<m;j++){
                    colSum[j] += matrix[down][j];
                }
                int result = INT_MIN;
                set<int> s;
                s.insert(0);
                int prefixSum = 0;
                for (int i = 0; i < colSum.size(); i++) {
                    prefixSum += colSum[i];
                    auto target = s.lower_bound(prefixSum - k);
                    if (target != s.end()) {
                        result = max(result, prefixSum - *target);
                    }
                    s.insert(prefixSum);
                }
                maxi = max(maxi, result);
            }
        }
        return maxi;
    }
};