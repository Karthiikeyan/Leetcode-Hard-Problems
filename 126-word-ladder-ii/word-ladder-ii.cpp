class Solution {
    string b;
private:
    void dfs(string word, vector<string> &v, unordered_map<string,int> mp, vector<vector<string>> &ans){
        // Base case: when we reach the beginning word, add the current path to the answer
        if(word==b) {
            reverse(v.begin(), v.end()); // Reverse the path to get it from start to end
            ans.push_back(v);
            reverse(v.begin(), v.end()); // Reverse it back to original order
            return;
        }
        int steps = mp[word]; // Number of steps taken to reach the current word
        for(int i=0;i<word.length();i++){
            char a = word[i]; // Save the original character to restore later
            for(char c='a';c<='z';c++){
                word[i] = c; // Try replacing the current character with every possible character
                if(mp.find(word)!=mp.end() && mp[word] ==steps -1){ // If this new word is in the map and was visited in the previous step
                    v.push_back(word); // Add the new word to the current path
                    dfs(word, v, mp, ans); // Recursively find all paths from this word
                    v.pop_back(); // Remove the new word from the path to try other possibilities
                }
            }
            word[i] = a; // Restore the original character
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_map<string, int> m;
        m[beginWord]=1; // Starting word has been visited in one step
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // Remove the starting word from the set
        int s = beginWord.size();
        while(!q.empty()){
            string word = q.front();
            int steps = m[word];
            q.pop();
            if(word==endWord) break; // If we reach the ending word, we're done
            for(int i=0;i<s;i++){
                char a=word[i];
                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(st.count(word)>0){ // If this new word is in the set, mark it as visited
                        q.push(word);
                        st.erase(word); // Remove it from the set so we don't visit it again
                        m[word]=steps+1; // Mark this word as visited in the next step
                    }
                }
                word[i]=a;
            }
        }
        vector<vector<string>> ans;
        vector<string> v;
        v.insert(v.begin(),endWord); // Start the path with the ending word
        dfs(endWord, v, m, ans); // Recursively find all paths from the ending word
        return ans;
    }
};