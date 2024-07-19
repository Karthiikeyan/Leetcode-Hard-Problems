class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            int n = temp.size();
            int maxi = -1;
            for(auto i:temp){
                maxi = max(maxi,i-'0');
            }
            nums[i] = maxi*stoi(string(n,'1'));
        }
        int tot = accumulate(nums.begin(),nums.end(),0);
        return tot;
    }
};