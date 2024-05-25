class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int result = 0;
        for(int i=n-1;i>=0;i--){
            if(result!=0 && s.charAt(i)==' ') break;
            else if(s.charAt(i)==' ') continue;
            else result++;
        }
        return result;
    }
}