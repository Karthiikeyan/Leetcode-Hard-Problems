class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int appsum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int ans = 0;
        int sum = 0;
        for (auto it : capacity) {
            if (sum >= appsum) {
                return ans;
            } else {
                ans++;
                sum += it;
            }
        }
        return ans;
    }
};