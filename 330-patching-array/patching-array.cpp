class Solution{
public:
    int minPatches(vector<int> &nums, int n)
    {
        ios_base::sync_with_stdio(0);
        long long int currentSum = 1; 
        int patches = 0, index = 0;  

        while (currentSum <= n){
            if (index < nums.size() && nums[index] <= currentSum){
                currentSum += nums[index];; 
                index++;
            }
            else{
                currentSum += currentSum;
                patches++;
            }
        }
        return patches;
    }
};