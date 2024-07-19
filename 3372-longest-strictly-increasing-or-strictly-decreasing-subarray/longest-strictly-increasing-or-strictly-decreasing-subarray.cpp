class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int delen = 1, inlen = 1;
        int tmpd = 1, tmpi = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i]){
                tmpi++;
            }        
            else{
                tmpi = 1;
            }
            inlen = max(tmpi, inlen);
            
            if(nums[i - 1] > nums[i]){
                tmpd++;
            }
            else{
                tmpd = 1;
            }
            delen = max(tmpd, delen);
        } 
        return max(delen, inlen);
    }
};