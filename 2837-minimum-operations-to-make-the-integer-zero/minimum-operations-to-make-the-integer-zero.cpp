#define ll long long int
class Solution {
private:
    int countBit(ll x){
        int result = 0;
        for(int j=0; j<64;j++){
            if((1LL << j) & x) result++;
        }
        return result;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 == 0) return 0;
        for(ll i=0;i<36;i++){
            ll req = (ll)num1 - i*num2;
            if(countBit(req) <= i && i <= req){
                return i;
            }
        }
        return -1;
    }
};