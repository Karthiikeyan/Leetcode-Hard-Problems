class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int N = n+1;
        vector<int> pref(n+1, 0), suff(n+1, 0);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1];
            suff[N-i-1] = suff[N-i] + nums[n-i];
        }
        for(int i=0;i<=n;i++){
            cout<<pref[i]<<" ";
        }cout<<endl;
        for(int i=0;i<=n;i++){
            cout<<suff[i]<<" ";
        }cout<<endl;
        
        for(int i=0;i<n;i++){
            if(pref[i]==suff[i+1]) return i;
        }
        return -1;
    }
};