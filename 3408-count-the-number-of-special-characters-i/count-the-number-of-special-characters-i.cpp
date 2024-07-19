class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        unordered_set<char>s;
        for(int i=0;i<word.length();i++){
            s.insert(word[i]);
        }
        for(char c:s){
            if(s.find(c+32)!=s.end())count++;
        }
        return count;
    }
};