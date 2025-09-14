#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> exactWords;
    unordered_map<string, string> caseInsensitive;
    unordered_map<string, string> vowelMasked;

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string maskVowels(const string &s) {
        string res = toLower(s);
        for (char &c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;

        // Preprocess wordlist
        for (string &word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end())
                caseInsensitive[lowerWord] = word;

            string masked = maskVowels(word);
            if (vowelMasked.find(masked) == vowelMasked.end())
                vowelMasked[masked] = word;
        }

        // Process queries
        for (string &query : queries) {
            if (exactWords.count(query)) {
                ans.push_back(query);
            } 
            else {
                string lowerQuery = toLower(query);
                if (caseInsensitive.count(lowerQuery)) {
                    ans.push_back(caseInsensitive[lowerQuery]);
                }
                else {
                    string maskedQuery = maskVowels(query);
                    if (vowelMasked.count(maskedQuery)) {
                        ans.push_back(vowelMasked[maskedQuery]);
                    } 
                    else {
                        ans.push_back("");
                    }
                }
            }
        }
        return ans;
    }
};
