class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        
        int num1 = 0, num2 = 0;
        for(int i=0,j=0;i<n || j<m;i++,j++){
            while(i<n && version1[i]!='.')
                num1 = (num1*10) + (version1[i++]-'0');
            while(j<m && version2[j]!='.')
                num2 = (num2*10) + (version2[j++]-'0');
            if(num1>num2) return 1;
            if(num1<num2) return -1;
            num1 = 0, num2 = 0;
        }
        return 0;
    }
};