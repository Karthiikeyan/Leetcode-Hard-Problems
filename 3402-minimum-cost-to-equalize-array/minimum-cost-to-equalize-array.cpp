#define MOD 1000000007

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& A, int c1, int c2) {
        int ma = *max_element(A.begin(), A.end());
        int mi = *min_element(A.begin(), A.end());
        int n = A.size(), mod = 1000000007;
        long long su = accumulate(A.begin(), A.end(), 0LL);
        long long total = 1LL * ma * n - su;

        // case 1
        if (c1 * 2 <= c2 || n <= 2) {
            return (total * c1) % mod;
        }

        // case 2
        long long op1 = max(0LL, (ma - mi) * 2 - total);
        long long op2 = total - op1;
        long long res = (op1 + op2 % 2) * c1 + op2 / 2 * c2;

        // case 3
        total += op1 / (n - 2) * n;
        op1 %= n - 2;
        op2 = total - op1;
        res = min(res, (op1 + op2 % 2) * c1 + op2 / 2 * c2);

        // case 4
        for (int i = 0; i < 2; i++) {
            total += n;
            res = min(res, total % 2 * c1 + total / 2 * c2);
        }

        return res % mod;
    }
};
