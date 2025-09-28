class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        sort(arr2.begin(), arr2.end());
        for(auto val : arr1){
            int mini = val - d;
            int curr = lower_bound(arr2.begin(), arr2.end(), mini) - arr2.begin();
            if(curr==arr2.size() || arr2[curr]> val+d){
                count++;
            }
        }
        return count;
    }
};