class Solution {
private:
    void rec(int ind, vector<int>&nums, vector<vector<int>>&ans, vector<int> temp){

        //base case
        if(ind<0){
            ans.push_back(temp);
            return;
        }
        
        //rec case
        temp.push_back(nums[ind]);
        rec(ind-1, nums, ans, temp);
        temp.pop_back();
        rec(ind-1, nums, ans, temp);
    }
public: 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        rec(n-1, nums, ans, temp);
        return ans;
    }
};