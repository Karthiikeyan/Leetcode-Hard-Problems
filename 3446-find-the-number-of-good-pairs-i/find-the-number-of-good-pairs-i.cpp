class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int j = 0; j < nums2.size(); ++j) {
            long long num = nums2[j] * k;
            for (int i = 0; i < nums1.size(); ++i) {
                if (nums1[i] % num == 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};