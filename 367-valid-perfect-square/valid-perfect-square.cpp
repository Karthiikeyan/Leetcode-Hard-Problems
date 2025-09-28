class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left<=right){
            int mid = left + (right - left)/2;
            long long sqr = (long long)mid * mid; // Corrected line
            if(sqr==num) return true;
            else if(sqr<num){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};