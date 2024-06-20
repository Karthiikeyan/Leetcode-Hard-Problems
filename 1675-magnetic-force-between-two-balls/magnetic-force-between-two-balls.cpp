class Solution {
private:
    int check(int mid, vector<int>&position, int m, int n){
        int val = 0;
        int isEnd = 0;
        while(isEnd!=n){
            val++;
            isEnd = lower_bound(position.begin(), position.end(), position[isEnd] + mid) - position.begin();
        }
        cout<<val<<endl;
        return val>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low=1, high=1e9;
        int ans = -1;
        while(low<=high){
            int mid = low + ((high - low)/2);
            cout<<low<<" "<<mid<<" "<<high<<endl;
            if(check(mid, position, m, n)){
                ans = mid;
                low = mid + 1;
            }else
                high = mid - 1;
            cout<<"ans : "<<ans<<endl;
        }
        return ans;
    }
};