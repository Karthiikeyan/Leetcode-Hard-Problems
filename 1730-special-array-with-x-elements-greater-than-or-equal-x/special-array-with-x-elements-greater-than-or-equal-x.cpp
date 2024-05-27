class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count=0;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i){
                    count++;
                }
            }
            if(count==i){
                return count;
            }
            count=0;
        }
       return -1; 
    }
};