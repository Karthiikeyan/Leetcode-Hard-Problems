class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(1e5+5, 0);
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<=1e5) v[nums[i]-1]++;
        }
        int i=0;
        while(i<=1e5){
            if(v[i]==0) return i+1;
            i++;
        }
        return i;
    }
};