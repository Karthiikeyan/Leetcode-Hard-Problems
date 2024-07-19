class Solution {
    public String getEncryptedString(String s, int k) {
        int n = s.length();
        String res="";
        k=k%n;
        for(int i=k;i<n;i++){
            res+=s.charAt(i);
        }
        for(int i=0;i<k;i++){
            res+=s.charAt(i);
        }
        return res;
    }
}