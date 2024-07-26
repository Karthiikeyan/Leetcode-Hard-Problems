struct Node {
    int cnt;
    unordered_map<char, Node*> child; // Use unordered_map for child nodes

    Node() : cnt(0) {}
};

struct Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insertString(const string &s) {
        insert(root, 0, s);
    }

    int findQuery(const string &s) {
        return solveQuery(root, 0, s);
    }

private:
    void insert(Node* node, int i, const string &s) {
        if (i == s.size()) return;
        
        char c = s[i];
        if (node->child.find(c) == node->child.end()) {
            node->child[c] = new Node();
        }

        node->child[c]->cnt++;
        insert(node->child[c], i + 1, s);
    }

    int solveQuery(Node* node, int i, const string &s) {
        if (node == NULL) return 0;
        if (i == s.size()) return node->cnt;

        char c = s[i];
        if (node->child.find(c) == node->child.end()) return node->cnt;

        return node->cnt + solveQuery(node->child[c], i + 1, s);
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        int n = words.size();
        for(int i=0;i<n;i++){
            trie.insertString(words[i]);
        }

        for(int i=0;i<n;i++){
            int val = trie.findQuery(words[i]);
            ans.push_back(val);
        }
        return ans;
    }
};