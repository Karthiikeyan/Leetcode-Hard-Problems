class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> ind;
        vector<int> arr, ans(n, -1);

        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            arr.push_back(start);
            ind.push_back({start, i});
        }
        sort(arr.begin(), arr.end());
        sort(ind.begin(), ind.end());
        for(int i=0;i<n;i++){
            int val = intervals[i][1];
            int lb = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
            if(lb==n) continue;
            int index = ind[lb].second;
            ans[i] = index;
        }
        return ans;
    }
};