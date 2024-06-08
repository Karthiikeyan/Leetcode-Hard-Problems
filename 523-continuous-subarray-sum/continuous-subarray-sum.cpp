class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;

        unordered_map<int,int> mpp;
        mpp[0] = -1;
        unsigned long long int prefix = 0;

        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix % k;

            if(mpp.find(rem)!=mpp.end()){
                if(i - mpp[rem] > 1) return true;
            }else{
                mpp[rem] = i;
            }
        }

        return false;
    }
};