class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        int i = 0;
        int j = k - 1;
        vector<int> temp = {nums.begin(), nums.begin() + k - 1};
        sort(temp.begin(), temp.end());
        while (j < n) {
            temp.insert(lower_bound(temp.begin(), temp.end(), nums[j]),
                        nums[j]);

            if (k & 1) {
                double median = (double)temp[k / 2];
                res.push_back(median);
            } else {
                int idx = k / 2;
                double median1 = (double)temp[idx];
                double median2 = (double)temp[idx - 1];
                res.push_back((median1 + median2) / 2);
            }

            temp.erase(lower_bound(temp.begin(), temp.end(), nums[i]));
            i++;
            j++;
        }

        return res;
    }
};