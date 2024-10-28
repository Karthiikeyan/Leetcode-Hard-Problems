class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        vector<int> exist(1e5+5, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < exist.size()) { // Ensure nums[i] is within bounds
                exist[nums[i]] = 1;
            }
        }
        unordered_set<int> st;

        int maxi = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            long long num = nums[i]; // Use long long to prevent overflow
            if (!st.count(num)) {
                while (num < exist.size() && exist[num]) { // Check bounds of exist
                    st.insert(num);
                    cnt += 1;
                    num *= num;
                    if (num >= exist.size()) break; // Stop if num is out of bounds
                }
                if (cnt > 1) { // Ensure we only consider streaks longer than 1
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};
