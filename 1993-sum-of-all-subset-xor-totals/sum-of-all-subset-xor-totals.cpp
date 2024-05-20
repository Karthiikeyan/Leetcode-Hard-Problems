class Solution {
public:
vector<int> ans;
vector<int> ds;

void generateSubs(vector<int> &nums , int index){
    if(index == nums.size()){
        int xorAns=0;
        for(auto &i:ds){
            xorAns ^= i;
        }
        ans.push_back(xorAns);
        return;
    }
    ds.push_back(nums[index]);
    generateSubs(nums,index+1);
    ds.pop_back();
    generateSubs(nums,index+1);
}
int subsetXORSum(vector<int>& nums) {

    generateSubs(nums,0);
    return accumulate(ans.begin(),ans.end(),0);

}
};