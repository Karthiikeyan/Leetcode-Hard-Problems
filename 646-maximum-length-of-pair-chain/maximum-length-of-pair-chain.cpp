class Solution {
static bool compare(vector<int>&a, vector<int>&b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 0;
        int second = -1e9;
        int n = pairs.size();
        for(int i=0;i<n;i++){
            if(second==-1e9 || second<pairs[i][0]){
                second = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};