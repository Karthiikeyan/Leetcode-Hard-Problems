class Solution {
private:
    int findLength(int x){
        int len = 0;
        while(x){
            len++;
            x /= 10;
        }
        return len;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mpp;
        for(int i=0;i<arr1.size();i++){
            int num = arr1[i];
            int len = findLength(num);
            while(num){
                mpp[num] = len--;
                num /= 10;
            }
        }
        int maxi = 0;
        for(int i=0;i<arr2.size();i++){
            int num = arr2[i];
            while(num){
                if(mpp.find(num)!=mpp.end()){
                    maxi = max(maxi, mpp[num]);
                }
                num /= 10;
            }
        }
        return maxi;
    }
};