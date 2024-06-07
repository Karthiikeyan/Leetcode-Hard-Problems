class Solution {
public:
    int mod = 1e9+7;
    int dp[101][10][2][2];

    void subtract1(string &a){
        int n = a.size();
        int i=n-1;
        while(a[i]=='0')i--;
        a[i]--;
        i++;
        while(i<=n-1) a[i++]='9';
    }

    int help(string &a, int n, int index, int prev, int strict, int isZero){
        if(index==n)return 1;
        if(dp[index][prev][isZero][strict]!=-1)return dp[index][prev][isZero][strict];
        int res = 0;
        int limit = strict ? a[index]-'0' : 9;
        if(isZero){
            for(int i=0; i<=limit; i++){
                res += help(a, n, index+1, i, strict&&(i==limit), isZero&&(i==0));
                res %= mod;
            } 
        }
        else{
            int option1 = prev-1, option2 = prev+1;
            if(option1>=0 && option1<=limit){
                res += help(a, n, index+1, option1, strict&&(option1==limit), 0);
                res %= mod;
            }
            if(option2>=0 && option2<=limit){
                res += help(a, n, index+1, option2, strict&&(option2==limit), 0);
                res %= mod;
            }
        }
        return dp[index][prev][isZero][strict] = res;
    }

    int countSteppingNumbers(string low, string high) {
        subtract1(low);
        int n = low.size(), m = high.size();
        memset(dp, -1, sizeof(dp));
        int lo = help(low, n, 0, 0, 1, 1);
        memset(dp, -1, sizeof(dp));
        int hi = help(high, m, 0, 0, 1, 1);
        cout<<lo<<" "<<hi;
        return (hi-lo+mod)%mod;
    }
};