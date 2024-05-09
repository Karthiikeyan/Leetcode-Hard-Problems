class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        for(int i=0;i<n && k>0;i++){
            long long val =  happiness[n-i-1] - i;
            if(val>0)
                ans += val;
            k--;
        }
        return ans;
    }
};