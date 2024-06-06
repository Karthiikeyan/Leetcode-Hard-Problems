class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        int cnt, curr;
        for(int i=0;i<n;i++){
            if(mpp[hand[i]]!=0){
                cnt = 1;
                curr = hand[i];
                mpp[hand[i]]--;
            
                while(cnt!=groupSize){
                    if(mpp.find(curr+1)==mpp.end() || mpp[curr+1]==0) return false;
                    curr = curr + 1;
                    mpp[curr]--;
                    cnt++;
                }
            }
        }

        return true;
    }
};