class Solution {
public:
    long long solve(int ind, int pos, vector<int> &nums, vector<vector<long long>> &dp){
    if (ind == nums.size())
        return 0;

    if (dp[ind][pos] != -1)
        return dp[ind][pos];

    long long nonpick = solve(ind + 1, pos, nums, dp);
    long long pick = 0;

    if (pos)
        pick = (long long)nums[ind] + solve(ind + 1, !pos, nums, dp);
    else
        pick = (long long)-nums[ind] + solve(ind + 1, !pos, nums, dp);

    return dp[ind][pos] = max(pick, nonpick);
}

long long maxAlternatingSum(vector<int> &nums)
{
    vector<vector<long long>> dp((long long)nums.size(), vector<long long>(2, -1));
    return solve(0, 1, nums, dp);
}
};